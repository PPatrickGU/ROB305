/* =====================================================================================================================
 * FifoConsumer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class FifoConsumer which consumes tokens to the box
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef FifoConsumer_h_INCLUDED
#define FifoConsumer_h_INCLUDED

#include <pthread.h>
#include "Mutex.h"
#include "Thread.h"
#include "Fifo.hpp"


class FifoConsumer : public Thread
{
private:
	// Pointer to the object fifo 
	Fifo<int> *fifo;

	// Number of tokens that have been consumed
	unsigned counter;	
	
public:
	// Constructor 
	FifoConsumer(Fifo<int> *fif);

	// Destructor
	~FifoConsumer();

	// Handling function
	void run();

	// Get tne number of tokens already consumed
	unsigned getCounter();
};

#endif
