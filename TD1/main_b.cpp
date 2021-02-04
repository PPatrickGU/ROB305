#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string.h>


int value = 0;
 
void myHandler(int, siginfo_t* si, void*)
{
    std::cout << "Counter: " <<  *((int*)si->si_value.sival_ptr)<<  std::endl;
    *((int*)si->si_value.sival_ptr) += 1;
}

 
int main()
{
    // define the sigaction 
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;  // in order to use the sa_sigaction as the call_back function
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

	// define the sigevent
    struct sigevent sev;  
    sev.sigev_notify = SIGEV_SIGNAL;  
    sev.sigev_signo = SIGRTMIN;
    int value = 0;   
    sev.sigev_value.sival_ptr = (void*)&value; 

    struct itimerspec its;  
    timer_t tid;  
    int ret;  	
	ret = timer_create(CLOCK_REALTIME, &sev, &tid);
	if (ret)
		perror("timer_create");

	its.it_interval.tv_sec = 0;  // the time interval
	its.it_interval.tv_nsec = 5e8;
	its.it_value.tv_sec = 1; // the delay time start
	its.it_value.tv_nsec = 0;


	ret = timer_settime(tid, 0, &its, NULL);
	if (ret)
		perror("timer_settime");

	while(value < 15)
		continue;

	timer_delete(tid);
	return 0;
}

 
