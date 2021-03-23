/* =====================================================================================================================
 * Mutex.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implement the class of Mutex
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Mutex.h"
#include "timespec.h"
#include <pthread.h>

Mutex::Mutex(bool isInversionSafe)
{
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
    if(isInversionSafe) //Add the possibility to invert the priority
    {
        pthread_mutexattr_setprotocol(&mutexAttr, PTHREAD_PRIO_INHERIT); 
    }
    pthread_mutex_init(&posixId, &mutexAttr);
    pthread_cond_init(&posixCondId, NULL);
    pthread_mutexattr_destroy(&mutexAttr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}

void Mutex::lock()
{
    pthread_mutex_lock(&posixId);
}

bool Mutex::lock(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return ! (bool) pthread_mutex_timedlock(&posixId, &timeout_ts);
}


bool Mutex::trylock()
{
    return ! (bool) pthread_mutex_trylock(&posixId);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
}


Mutex::Monitor::Monitor(Mutex& m) : mutex(m){}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&mutex.posixCondId, &mutex.posixId);
}


bool Mutex::Monitor::wait(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return !(bool) pthread_cond_timedwait(&mutex.posixCondId, &mutex.posixId, &timeout_ts);
}


void Mutex::Monitor::notify()
{
    pthread_cond_signal(&mutex.posixCondId);
}


void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&mutex.posixCondId);
}

const char* Mutex::Monitor::TimeoutException::launchingException() const noexcept
{
    return "Time out Exception";
}


Mutex::Lock::Lock(Mutex& m) : Mutex::Monitor(m)
{
    mutex.lock();
}

Mutex::Lock::Lock(Mutex& m, double timeout_ms) : Mutex::Monitor(m)
{
    if(mutex.lock(timeout_ms) == false)
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::Lock::~Lock()
{
    mutex.unlock();
}


Mutex::TryLock::TryLock(Mutex& m) : Mutex::Monitor(m)
{
    if(mutex.trylock() == false)
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::TryLock::~TryLock()
{
    mutex.unlock();
}
