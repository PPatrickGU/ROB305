/* =====================================================================================================================
 * Thread.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class Thread 
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Thread.h"
#include "Chrono.h"
#include "timespec.h"
#include <pthread.h>
#include <iostream>

Thread::Thread()
{}

Thread::~Thread() 
{}

bool Thread::start()
{	

    if(!started)
    {	
        startTime = timespec_now();
        PosixThread::start(call_run, (void*) this);
        stopTime = timespec_now();
        started = true;
    }

    return started;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return timespec_to_ms(startTime);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(stopTime);
}

double Thread::execTime_ms()
{
    return timespec_to_ms(stopTime - startTime);
}

void* Thread::call_run(void* v_thread)
{
    Thread* thread = (Thread*) v_thread;
    thread->run();
    return (void*) thread;
}
