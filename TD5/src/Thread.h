/* =====================================================================================================================
 * Thread.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class Thread deriving from PosixThread
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED

#include "PosixThread.h"
#include "timespec.h"
#include <time.h>


class Thread : public PosixThread
{
public:
	// Constructor
	Thread();

	// Destructor
	~Thread();
	
	// Start the Thread
	bool start();
	
	// Make the thread sleep for a given duration
	static void sleep_ms(double delay_ms);


	// Get the strating time of the thread 
	double startTime_ms();
	
	// Get the stopping time of the thread 
	double stopTime_ms();
	
	// Get the duration of the thread
	double execTime_ms();

protected:
	virtual void run() = 0; //	virtual void function that will be implemented by the derivate class

private:	
	static void * call_run(void* v_thread);

	timespec startTime;

	timespec stopTime;

	bool started = false;
};

#endif