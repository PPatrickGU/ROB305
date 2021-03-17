/* =====================================================================================================================
 * main_b.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to get familiar with the priority the pthread
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include <unistd.h>
#include "timespec.h"
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string>
#include <pthread.h>



struct Data {
	volatile unsigned int nLoops;
	volatile double counter;
};

void incr(volatile unsigned int nLoops, volatile double* pCounter)
{
	for (unsigned i=0; i<nLoops; i++)
	{
		*pCounter += 1.0;
	}
}
 
void* call_incr(void* v_data)
{
	Data* p_data = (Data*) v_data;
	incr(p_data -> nLoops, &p_data -> counter);
	return v_data;
}


int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		// Input parameters
		unsigned int nLoops = std::stoi(argv[1]);
		unsigned int nTasks = std::stoi(argv[2]);
		int schedPolicy;
		if(std::string(argv[3]) == "SCHED_RR") schedPolicy = SCHED_RR;               
    	else if(std::string(argv[3]) == "SCHED_FIFO") schedPolicy = SCHED_FIFO;      
    	else schedPolicy = SCHED_OTHER;

		// Main priority
		struct sched_param schedParam;
		schedParam.sched_priority = sched_get_priority_max(schedPolicy);
		pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

		// Thread priority
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
		pthread_attr_setschedpolicy(&attr, schedPolicy);
		sched_param schedParams;
		int priority = rand()%100 + 1; 
	    if (priority == 100) priority = priority - 2;  // Get a random number between 1 and 98 (because priority_main = 99)
		schedParams.sched_priority = (schedPolicy == SCHED_OTHER) ? 0 : priority;
		pthread_attr_setschedparam(&attr, &schedParams);

		Data data = {nLoops, 0.0};

		// Create pthreads
		pthread_t incrementThread[nTasks];
		struct timespec begin, end;
		clock_gettime(CLOCK_REALTIME, &begin);
		for (unsigned int i=0;i<nTasks;i++)
		{
			pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
		}

		// Join pthreads
		for (unsigned int i=0; i<nTasks;i++) pthread_join(incrementThread[i], NULL);
		pthread_attr_destroy(&attr);

		clock_gettime(CLOCK_REALTIME, &end);

		std::cout << "Duration : " << timespec_to_ms(end - begin)  << " ms" << std::endl;
		std::cout << "Counter : " <<  data.counter << std::endl;
	}
	else
	{
		std::cout << "Error: number of arguments. 3 expected." << std::endl;
	}

	return 0;
}
