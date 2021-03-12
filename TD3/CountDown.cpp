/* =====================================================================================================================
 * PerodicTimer.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class of CountDown
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */


#include "CountDown.h"
#include <iostream>
#include <signal.h>
#include <iostream>


CountDown::CountDown(int n)
{
    count = n;
}

int CountDown::getCount()
{
    return count;
}

void CountDown::callback()
{
   	if (count >= 0)
   	{
   		std::cout << "Counter value : " << count << std::endl;
    	count--;
   	}
	else
	{
        std::cout << "\n---STOPPING---\n" << std::endl;
        CountDown::stop();
    }
}