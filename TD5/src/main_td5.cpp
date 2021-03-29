/* =====================================================================================================================
 * main_td5.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function for TD5
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Mutex.h"
#include "timespec.h"
#include "CpuLoopMutex.h"
#include "Calibrator.h"
#include "Chrono.h"
#include <time.h>
#include <iostream>

int main() 
{
	// Work on a single CPU
	cpu_set_t  cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);
	sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);

	// Mutex with control on the inversion
	Mutex mutex(false);	
	Chrono chrono;

	Calibrator calib(100,5);
	CpuLoop cpulA(calib);
	CpuLoop cpulB(calib);
	CpuLoop cpulC(calib);

	// Set policy and priority
	int policy = SCHED_RR;
	int priorityA = 90;
	int priorityB = 60;
	int priorityC = 30;
		
	// Create threads with mutex 
	CpuLoopMutex A(&cpulA, policy, priorityA, &mutex, 40, 10, 10);
	A.setScheduling(policy, priorityA);

	CpuLoopMutex B(&cpulB, policy, priorityB, &mutex, 10, -1, -1);
	B.setScheduling(policy, priorityB);

	CpuLoopMutex C(&cpulC, policy, priorityC, &mutex, 50, 20, 20);
	C.setScheduling(policy, priorityC);

	//Start thread C and waiting for activating A and B
	std::cout << "---Start of Thread C (priority 30)---" << std::endl;
	C.start();
	timespec_wait(timespec_from_ms(3000));
	std::cout << "---Start of Thread A (priority 90) and B (priority 60)---\n" << std::endl;
	A.start();
	B.start();
		
	//Join Threads
	A.join();
	C.join();
	B.join();
		
	chrono.stop();
	std::cout << "Ticks taken by A : " << A.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << " ticks " << std::endl;
	std::cout << "Ticks taken by B : " << B.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << " ticks " << std::endl;
	std::cout << "Ticks taken by C : " << C.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << " ticks " << std::endl;
	
	std::cout << "Execution Time of main : " << chrono.lap() << " ms"<< std::endl;
	return 0;
}
