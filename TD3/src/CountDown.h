/* =====================================================================================================================
 * PeriodicTimer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a class implementing a countdown by deriving from PeriodicTimer.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef CountDown_h_INCLUDED
#define CountDown_h_INCLUDED

#include "PeriodicTimer.h"

class CountDown : public PeriodicTimer
{
private:
	int count;

public:
	CountDown(int n);
	int getCount();

protected:
	// implementation of the pure virtual function Callback()
	void callback();
};


#endif
