/* =====================================================================================================================
 * main_td1e.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to realize the operation of calibration
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include <unistd.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "timespec.h"
#include <climits>
#include "signal.h"

unsigned int incr(unsigned int nLoops, double* pCounter, bool* pStop);
void myHandler(int, siginfo_t* si, void*);
unsigned int mesure();
std::array<double,2> calib();

void myHandler(int, siginfo_t* si, void*)
{
    *((bool*)si->si_value.sival_ptr) = true;
    // std::cout << "stop is set true: " <<  *((bool*)si->si_value.sival_ptr) <<  std::endl;
}

unsigned int incr(unsigned int nLoops, double* pCounter, bool* pStop)
{ 
    unsigned int iLoop = 0;
    for(iLoop = 0; iLoop < nLoops; ++iLoop)
    {
        if (*pStop == true) break;
		*pCounter += 1.0;
    }
    return iLoop;
}

unsigned int mesure(time_t sec, long nsec)
{
	bool stop = false;
	unsigned int nLoops = UINT_MAX;
    double counter = 0.0;

	struct sigaction sa;
    timer_t tid; 

	// define the sigaction 
    sa.sa_flags = SA_SIGINFO;  // in order to use the sa_sigaction as the call_back function
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);
	
	// define the sigevent
	struct sigevent sev;      
    sev.sigev_notify = SIGEV_SIGNAL;  //SIGEV_SIGNAL
    sev.sigev_signo = SIGRTMIN;  
    sev.sigev_value.sival_ptr = (void*)&stop; 
    int ret;  	
	ret = timer_create(CLOCK_REALTIME, &sev, &tid);
	if (ret)
		perror("timer_create");

	struct itimerspec its; 
	its.it_interval.tv_sec = 0;  // the time interval
	its.it_interval.tv_nsec = 0;
	its.it_value.tv_sec = sec; // the delay time start
	its.it_value.tv_nsec = nsec;
	ret = timer_settime(tid, 0, &its, NULL);
	if (ret)
		perror("timer_settime");

   	struct timespec time_begin, time_end;
	time_begin = timespec_now();
    unsigned int iLoop = incr(nLoops, &counter, &stop); 
    iLoop += 0;         
    time_end = timespec_now(); 

    std::cout << std::fixed << std::setprecision(9) <<  "Counter value: " << counter << ", Time needed: " << timespec_to_ms(time_end - time_begin)/1000 << " seconds" <<std::endl; 

	timer_delete(tid);
	return iLoop;
}


// Calibration using regression
std::array<double,2> calib_reg(int numCalibs)
{	
	std::array<double,2> parameters;
	double a = 0;
	double b = 0;
	double r[numCalibs], t[numCalibs];
	for(int i = 0; i < numCalibs; i++)
    {
        std::cout << "Calib NO." << i+1 << std::endl;
        t[i] = i;
        r[i] = (double)mesure(i+1, 0);
    }
	
	long double sum_x = 0;
	long double sum_xx = 0;
	long double sum_y = 0;
	long double sum_xy = 0;

	for (int i= 0; i< numCalibs; i++)
	{
		sum_x += t[i];
		sum_y += r[i];
		sum_xx += t[i]*t[i];
		sum_xy += r[i]*t[i]; // x*y
	}

	a = (double) (numCalibs * sum_xy - sum_x * sum_y) / (double)(numCalibs * sum_xx - sum_x * sum_x);
	b = (double) sum_y / numCalibs - a * sum_x / (double)numCalibs;
    parameters[0] = a;
    parameters[1] = b;

	return parameters;
}



int main(int , char**)
{
	std::cout << "---Start of calibration using linear regression---"  << std::endl;    
	std::array<double,2> parameters;
	int numCalibs = 5;
	parameters = calib_reg(numCalibs);
	std::cout << "\nesults : a = " << parameters[0]<< ", b = " <<  parameters[1] << std::endl;  

	std::cout << "\nStart testing the parameters of the calibration:"  << std::endl;  
	unsigned int loop = mesure(10, 0);
	unsigned int loopCal = parameters[0]*10 + parameters[1];
	std::cout << "Number of loops calculated for 10 seconds is: "  << parameters[0]*10 + parameters[1] << std::endl;
	std::cout << "Accuracy : " << (1-(abs(loop - loopCal) / double(loop) ))*100 << "%" << std::endl;
	std::cout << "---End of calibration---"  << std::endl; 
	return 0;

}



