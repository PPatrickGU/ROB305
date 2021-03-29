/* =====================================================================================================================
 * Looper.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a Looper class which cycles until achieving the stop condition.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef Looper_h_INCLUDED
#define Looper_h_INCLUDED

#include <cfloat>
#include <limits>
#include "PeriodicTimer.h"

class Looper
{
private:
	// Stop the looper when doStop is true
	volatile bool doStop; 

	// Current number of loops executed
	double iLoop; 

public:
	// Runs a given number of iterations of a loop 
	double runLoop(double nLoops = __DBL_MAX__); 

	// Return the current number of loops executed
	double getSample(); 

	// Stop the looper and return the number of loops executed
	double stopLoop(); 
};


#endif
