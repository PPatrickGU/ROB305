/* =====================================================================================================================
 * PerodicTimer.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class of a perodic posix timer
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "PeriodicTimer.h"
#include "timespec.h"
#include <signal.h>
#include <iostream>

void PeriodicTimer::start(double duration_ms)
{

    itimerspec its;
    
    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval = timespec_from_ms(duration_ms);;

    timer_settime(timerId, 0, &its, NULL);

}