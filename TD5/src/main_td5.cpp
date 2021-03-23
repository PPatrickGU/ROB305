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
	Mutex mutex(true);	
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
	CpuLoopMutex A(&cpulA, policy, priorityA, &mutex, 4000, 1000, 2000);
	CpuLoopMutex B(&cpulB, policy, priorityB, &mutex, 1000, -1, -1);
	CpuLoopMutex C(&cpulC, policy, priorityC, &mutex, 5000, 2000, 2000);

	A.setScheduling(policy, priorityA);
	B.setScheduling(policy, priorityB);
	C.setScheduling(policy, priorityC);

	//Start thread C and waiting for activating A and B
	std::cout << "Start Thread C (priority 30)" << std::endl;
	C.start();
	timespec_wait(timespec_from_ms(3000));
	std::cout << "Start Thread A (priority 90) and B (priority 60)" << std::endl;
	A.start();
	B.start();
		
	//Join Threads
	A.join();
	C.join();
	B.join();
		
	chrono.stop();
	std::cout << "Time taken by A : " << A.execTime_ms() << " ms" << std::endl;
	std::cout << "Time taken by B " << B.execTime_ms() << " ms" << std::endl;
	std::cout << "Time taken by C " << C.execTime_ms() << " ms" << std::endl;
	
	std::cout << "Execytion Time of main : " << chrono.lap() << " ms"<< std::endl;
	return 0;
}
