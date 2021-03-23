/* =====================================================================================================================
 * IncrMutexThread.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class IncrMutexThread, which has a mutex compared with the class IncrThread .
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef IncrMutexThread_h_INCLUDED
#define IncrMutexThread_h_INCLUDED

#include "IncrThread.h"
#include "Mutex.h"
#include "data.h"
#include <time.h>

class IncrMutexThread : public IncrThread
{
public :
	// Constructor
	IncrMutexThread(Data* data, Mutex* mutex);

	// Destructor
	~IncrMutexThread();


protected :
	Mutex* mutex;

	void run();
};

#endif
