#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string.h>


int value = 0;
 
void signal_handle(int, siginfo_t* si, void*)
{
    std::cout << "Counter: " <<  *((int*)si->si_value.sival_ptr)<<  std::endl;
    *((int*)si->si_value.sival_ptr) += 1;
}

 
int main()
{
    // define the sigaction 
    struct sigaction sa, sa_old;
    memset(&sa, 0, sizeof(struct sigaction));
    memset(&sa_old, 0, sizeof(struct sigaction));

    sa.sa_flags = SA_SIGINFO;  // in order to use the sa_sigaction as the call_back function
    sa.sa_sigaction = signal_handle;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGIO, &sa, &sa_old);

	// define the sigevent
    struct sigevent evp;  
	memset(&evp, 0, sizeof(struct sigevent));
    
    int value = 0; 
    evp.sigev_notify = SIGEV_SIGNAL;  
    evp.sigev_signo = SIGIO;  
    evp.sigev_value.sival_ptr = (void*)&value; 

    struct itimerspec ts;  
    timer_t timer;  
    int ret;  	
	ret = timer_create(CLOCK_REALTIME, &evp, &timer);
	if (ret)
		perror("timer_create");

	ts.it_interval.tv_sec = 0;  // the time interval
	ts.it_interval.tv_nsec = 5e8;
	ts.it_value.tv_sec = 1; // the delay time start
	ts.it_value.tv_nsec = 0;


	ret = timer_settime(timer, 0, &ts, NULL);
	if (ret)
		perror("timer_settime");

	while(value < 15)
		continue;

	timer_delete(timer);
	return 0;
}

 
