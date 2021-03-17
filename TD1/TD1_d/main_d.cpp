/* =====================================================================================================================
 * main_d.cpp
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
    sev.sigev_signo = SIGIO;  
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
    time_end = timespec_now(); 

    std::cout <<  "Counter value: " << counter << std::fixed << std::setprecision(9) << ", Time needed: " << timespec_to_ms(time_end - time_begin)/1000 << " seconds" <<std::endl; 

	timer_delete(tid);
	return iLoop;
}

std::array<double,2> calib()
{	
	std::array<double,2> parameters;
	double I4 = (double)mesure(4, 0);
	double I6 = (double)mesure(6, 0);
	parameters[0] = (I6 - I4)/(6.0 - 4.0); 
	parameters[1] = I4 - parameters[0] * 4.0;
	return parameters;
}

int main(int argc, char* argv[])
{
	std::cout << "Start calibration:"  << std::endl;    
	std::array<double,2> parameters;
	parameters = calib();
	std::cout << "Results : a = " << parameters[0]<< ", b = " <<  parameters[1] << std::endl;  

	std::cout << "\nStart testing the parameters of the calibration:"  << std::endl;  
	mesure(10, 0);
	std::cout << "Number of loops calculated for 10 seconds is: "  << parameters[0]*10 + parameters[1] << std::endl;
	return 0;

}



