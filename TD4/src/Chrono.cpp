/* =====================================================================================================================
 * Chrono.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the Chrono class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Chrono.h"
#include "timespec.h"

Chrono::Chrono()
{
    startTime_ = timespec_now();
}

void Chrono::stop()
{
    stopTime_ = timespec_now();
}

void Chrono::restart()
{
    startTime_ = timespec_now();
    stopTime_ = timespec_now();
}

bool Chrono::isActive()
{
    return startTime_ == stopTime_;
}

double Chrono::startTime()
{
    return timespec_to_ms(startTime_);
}

double Chrono::stopTime()
{
    return timespec_to_ms(stopTime_);
}

double Chrono::lap()
{
    double lap = 0.0;
    if (isActive()) 
    {
    	lap = timespec_to_ms(timespec_now())-startTime();
    }
    else lap = stopTime() - startTime(); 
    return lap;
}