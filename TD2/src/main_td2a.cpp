/* =====================================================================================================================
 * main_td2a.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to get familiar with the creation and join of the pthread
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */


#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h> 
#include <string.h>
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
		// std::cout << "CounterTemp : " <<  *pCounter << std::endl;
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
	if (argc == 3)
	{
		unsigned int nLoops = std::stoi(argv[1]);
		unsigned int nTasks = std::stoi(argv[2]);

		Data data = {nLoops, 0.0};

		// create nTasks threads
		pthread_t incrementThread[nTasks];

		for (unsigned int i=0;i<nTasks;i++)
		{
			pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
		}
		// join threads
		for (unsigned int i=0; i<nTasks;i++) pthread_join(incrementThread[i], NULL);
		std::cout << "Counter : " <<  data.counter << std::endl;

	}
	else
	{
		std::cout << "Error: number of arguments. 2 expected." << std::endl;
	}

	return 0;
}
