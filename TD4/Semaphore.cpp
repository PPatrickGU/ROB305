/* =====================================================================================================================
 * Semaphore.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implement the class of Semaphore
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Semaphore.h"
#include "timespec.h"
#include <pthread.h>

Semaphore::Semaphore(unsigned initCount, unsigned maximumCount) : counter(initCount), maxCount(maximumCount)
{}

void Semaphore::give()
{
    Mutex::Lock lock(mutex);
    if(counter < maxCount) counter++; 
    lock.notify();
    lock.~Lock();
}

void Semaphore::take()
{
    Mutex::Lock lock(mutex);
    if (counter == 0)  // blocked when counter = 0
    {
        lock.wait();
    }
    else
    {
        counter--;
    }
    lock.notify();
    lock.~Lock();
}

bool Semaphore::take(double timeout_ms)
{
    Mutex::Lock lock(mutex);
    if (counter == 0)
    {
        lock.wait(timeout_ms);
        lock.notify();
        lock.~Lock();
        return false;
    }
    else 
    {
        counter--;
        lock.notify();
        lock.~Lock();
        return true;
    }
}
