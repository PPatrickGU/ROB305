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
void signal_handle(int, siginfo_t* si, void*);
unsigned int mesure();
std::array<double,2> calib();

void signal_handle(int, siginfo_t* si, void*)
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
	memset(&sa, 0, sizeof(struct sigaction));
    struct sigevent evp;  
    memset(&evp, 0, sizeof(struct sigevent));	
    timer_t timer; 

	// define the sigaction 
    sa.sa_flags = SA_SIGINFO;  // in order to use the sa_sigaction as the call_back function
    sa.sa_sigaction = signal_handle;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGIO, &sa, NULL);
	// define the sigevent    
    evp.sigev_notify = SIGEV_SIGNAL;  //SIGEV_SIGNAL
    evp.sigev_signo = SIGIO;  
    evp.sigev_value.sival_ptr = (void*)&stop; 
    int ret;  	
	ret = timer_create(CLOCK_REALTIME, &evp, &timer);
	if (ret)
		perror("timer_create");

	struct itimerspec ts; 
	ts.it_interval.tv_sec = 0;  // the time interval
	ts.it_interval.tv_nsec = 0;
	ts.it_value.tv_sec = sec; // the delay time start
	ts.it_value.tv_nsec = nsec;
	ret = timer_settime(timer, 0, &ts, NULL);
	if (ret)
		perror("timer_settime");

   	timespec time_begin, time_end;
	time_begin = timespec_now();
    unsigned int iLoop = incr(nLoops, &counter, &stop);          
    time_end = timespec_now(); 

    std::cout <<  "Counter value: " << counter << std::fixed << std::setprecision(9) << ", Time needed: " << timespec_to_ms(time_end - time_begin)/1000 << " seconds" <<std::endl; 

	timer_delete(timer);
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



