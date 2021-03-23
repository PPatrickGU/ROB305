/* =====================================================================================================================
 * main_td1b.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to have a try of the signal.h
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */



#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string.h>


int value = 0;

namespace td1b
{
void myHandler(int, siginfo_t* si, void*)
{
    int* p_counter = (int*)si->si_value.sival_ptr;
    *p_counter += 1; //p_counter[0]
    std::cout << "Counter: "<<*p_counter << std::endl;
}
} 

 
int main()
{
	volatile int counter = 0;

    // define the sigaction 
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;  // in order to use the sa_sigaction as the call_back function
    sa.sa_sigaction = td1b::myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

	// define the sigevent
    struct sigevent sev;  
    sev.sigev_notify = SIGEV_SIGNAL;  
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &counter; 
    
    timer_t tid;  
    int ret;  	
	ret = timer_create(CLOCK_REALTIME, &sev, &tid);
	if (ret)
		perror("timer_create");

	// launch timer
    struct itimerspec its;  
	its.it_value.tv_sec = 0; // the delay time start
	its.it_value.tv_nsec = 5e8;
	its.it_interval = its.it_value;  // the time interval

	ret = timer_settime(tid, 0, &its, NULL);
	if (ret)
		perror("timer_settime");

	while(counter < 15)
		continue;

	// destroy the timer
	timer_delete(tid);
	return 0;
}

 
