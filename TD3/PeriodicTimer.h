/* =====================================================================================================================
 * PeriodicTimer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a class implementing a periodic posix timer.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef PeriodicTimer_h_INCLUDED
#define PeriodicTimer_h_INCLUDED

#include "Timer.h"

class PeriodicTimer : public Timer
{
public:
	// Start the perodic timer
	void start(double duration_ms);
};


#endif