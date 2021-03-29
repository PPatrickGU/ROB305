/* =====================================================================================================================
 * SemaConsumer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class SemaConsumer which consumes tokens to the box
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef SemaConsumer_h_INCLUDED
#define SemaConsumer_h_INCLUDED

#include <pthread.h>
#include "Semaphore.h"
#include "Thread.h"


class SemaConsumer : public Thread
{
private:
	// Pointer to the object semaphore
	Semaphore *semaphore;

	// Number of tokens that have been consumed
	unsigned counter;	

	
public:
	// Constructor 
	SemaConsumer(Semaphore *sema);

	// Destructor
	~SemaConsumer();

	// Handling function
	void run();

	// Get tne number of tokens already consumed
	unsigned getCounter();
};

#endif
