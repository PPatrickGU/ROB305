#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string.h>


int value = 0;
 
void signal_handle(int sig_num)
{
	if(SIGUSR1 == sig_num)
    {
    	if (value < 15)
    	{
    		value += 1; 
    	    std::cout << value <<  std::endl;
    	}
    }
}

 
int main()
{
    struct sigevent evp;  
    struct itimerspec ts;  
    timer_t timer;  
    int ret;  

    memset(&evp, 0, sizeof(struct sigevent));

    evp.sigev_value.sival_ptr = &timer;  
    evp.sigev_notify = SIGEV_SIGNAL;  
    evp.sigev_signo = SIGUSR1;  
    signal(SIGUSR1, signal_handle);  
	
	ret = timer_create(CLOCK_REALTIME, &evp, &timer);
	if (ret)
		perror("timer_create");

	ts.it_interval.tv_sec = 0;  // the spacing time 
	ts.it_interval.tv_nsec = 5e8;
	ts.it_value.tv_sec = 0; // the delay time start
	ts.it_value.tv_nsec = 5e8;

	ret = timer_settime(timer, 0, &ts, NULL);
	if (ret)
		perror("timer_settime");

	int value = 0;
	while(value < 15)
		continue;
	timer_delete(timer);
	return 0;
}

 