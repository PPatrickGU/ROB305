/* =====================================================================================================================
 * CpuLoopMutex.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class CpuLoopMutex 
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef CpuLoopMutex_h_INCLUDED
#define CpuLoopMutex_h_INCLUDED

#include "CpuLoop.h"
#include "Thread.h"
#include "Mutex.h"
#include "Calibrator.h"
#include "timespec.h"

class CpuLoopMutex : public Thread
{
public:
	// Constructor
	CpuLoopMutex(CpuLoop *cl, int poli, int prior, Mutex *m, double timeB, double durationM, double timeE);

	// Destructor
	~CpuLoopMutex();

	// Pointer towards the cpuloop object
	CpuLoop *cpul;
	
	// Handling function
	void run();

private:
	// Pointer towards the mutex object
	Mutex *mutex;

	// Policy of the thread
	int policy;

	// Priority of the thread
	int priority;

	// Time the mutex needs to begin
	double timeBeginMutex = -1;

	// Duration time of the lock of the mutex
	double durationMutex = -1;

	// Time of the lock of the thread
	double timeExecution = -1;
};

#endif

