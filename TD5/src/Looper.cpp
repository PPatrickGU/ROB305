/* =====================================================================================================================
 * Looper.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the Looper class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Looper.h"
#include <iostream>

double Looper::runLoop(double nLoops)
{
    doStop = false;
    iLoop  = 0;
   	while (iLoop < nLoops && not doStop)
	{
		iLoop ++;
		//std::cout << iLoop << std::endl;
	}
	return iLoop;
}

double Looper::getSample()
{
    return iLoop;
}

double Looper::stopLoop()
{
    doStop = true;
    return iLoop;
}