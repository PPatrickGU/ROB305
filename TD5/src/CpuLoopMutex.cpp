/* =====================================================================================================================
 * CpuLooperMutex.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implement the CpuLoopMutex class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "CpuLoopMutex.h"
#include "Mutex.h"
#include "Thread.h"
#include <iostream>

double tick_to_ms(int ticks)
{
	double duration_ms = (double) ticks / CLOCKS_PER_SEC * 1e3;
	return duration_ms;
}

CpuLoopMutex::CpuLoopMutex(CpuLoop *cl, int poli, int prior, Mutex *m, double timeB, double durationM, double timeE) : Thread(), cpul(cl), mutex(m), policy(poli), priority(prior),timeBeginMutex(timeB), durationMutex(durationM), timeExecution(timeE)
{}

CpuLoopMutex::~CpuLoopMutex()
{}

void CpuLoopMutex::run()
{	
	// std::cout << timeBeginMutex << std::endl;
	if(timeBeginMutex != -1) // With mutex
	{
		cpul->runTime(tick_to_ms(timeBeginMutex)); // Time waited before getting the lock						
		Mutex::Lock lock(*mutex, 1000); // Lock
		std::cout << "Thread with priority " << priority << " WITH Mutex" << std::endl;
		cpul->runTime(tick_to_ms(durationMutex));	// Duration of the mutex
		lock.~Lock(); // Unlock
		cpul->runTime(tick_to_ms(timeExecution - (timeBeginMutex + durationMutex)));
	} // Finish execution
	else 	// Without mutex
	{
		cpul->runTime(tick_to_ms(timeExecution));		
		std::cout << "Thread with priority " << priority << " WITHOUT Mutex" << std::endl;
	}
}

