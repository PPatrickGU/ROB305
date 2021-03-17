/* =====================================================================================================================
 * IncrThread.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class IncrThread that increments a counter value.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef IncrThread_h_INCLUDED
#define IncrThread_h_INCLUDED

#include "Thread.h"
#include "data.h"
#include <time.h>

class IncrThread : public Thread
{

public :
	// Constructor
	IncrThread(Data* data);

	// Destructor
	~IncrThread();

	Data* data;

	void run();
};

#endif