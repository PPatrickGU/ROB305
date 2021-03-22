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


CpuLoopMutex::CpuLoopMutex(CpuLoop *cl, int poli, int prior, Mutex *m, double timeB, double durationM, double timeE) : Thread(), cpul(cl), mutex(m), policy(poli), priority(prior),timeBeginMutex(timeB), durationMutex(durationM), timeExecution(timeE)
{}

CpuLoopMutex::~CpuLoopMutex()
{}

void CpuLoopMutex::run()
{
	if(timeBeginMutex != -1) // With mutex
	{
		cpul->runTime(timeBeginMutex); // Time waited before getting the lock						
		Mutex::Lock lock(*mutex, 500); // Lock
		std::cout << "Thread with priority " << priority << " WITH Mutex" << std::endl;
		cpul->runTime(durationMutex);	// Duration of the mutex
		lock.~Lock(); // Unlock
		cpul->runTime(timeExecution - (timeBeginMutex + durationMutex));
	} // Finish execution
	else 	// Without mutex
	{
		cpul->runTime(timeExecution);		
		std::cout << "Thread with priority " << priority << " WITHOUT Mutex" << std::endl;
	}
}

