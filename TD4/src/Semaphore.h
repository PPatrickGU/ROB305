/* =====================================================================================================================
 * Semaphore.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the Semaphore class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
*/

#ifndef Semaphore_h_INCLUDED
#define Semaphore_h_INCLUDED

#include "Mutex.h"
#include <signal.h>
#include <climits>


class Semaphore
{
public :
	// Constructor of Semaphore class.
	Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);

	// Add a token
	void give();

	// Remove an token
	void take();

	// Remove an token ( whether to wait for a certain time if the box is empty)
	bool take(double timeout_ms);

private :
	// Number of tokens
	unsigned int counter; 

	// Maximal number of tokens that can be stored 
	unsigned int maxCount; 

	// Mutex object
	Mutex mutex; 
};

#endif
