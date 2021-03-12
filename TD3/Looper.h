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
	volatile bool doStop; // Stop the looper when doStop is true
	double iLoop; // Current number of loops executed

public:
	double runLoop(double nLoops = __DBL_MAX__); // Runs a given number of iterations of a loop 
	double getSample(); //Return the current number of loops executed
	double stopLoop(); //Stop the looper and return the number of loops executed
};


#endif