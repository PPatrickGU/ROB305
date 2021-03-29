/* =====================================================================================================================
 * SemaProducer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class Thread Productor which gives token to the box
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef SemaProducer_h_INCLUDED
#define SemaProducer_h_INCLUDED

#include <pthread.h>
#include "Semaphore.h"
#include "Thread.h"


class SemaProducer : public Thread
{
private:
	// Pointer to the object semaphore
	Semaphore *semaphore;
	
	// Number of tokens that have been given
	unsigned counter;	

	// Number of tokens wanted
	unsigned maxCount;
		
public:
	// Constructor 
	SemaProducer(Semaphore *sem, unsigned maxNum);

	// Destructor
	~SemaProducer();

	// Handling function
	void run();

	// Get tne number of tokens already given
	unsigned getCounter();
};

#endif
