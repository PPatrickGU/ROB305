/* =====================================================================================================================
 * IncrMutexThread.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class IncrMutexThread 
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "IncrMutexThread.h"
#include <iostream>

IncrMutexThread::IncrMutexThread(Data* data, Mutex* mutex): IncrThread(data), mutex(mutex)
{
	int priority = rand()%99 + 1;       // Priority between 1 and 99
    int schedPriority = data->schedPolicy == SCHED_OTHER ? 0 : priority;
    setScheduling(data->schedPolicy, schedPriority);
}

IncrMutexThread::~IncrMutexThread()
{}

void IncrMutexThread::run()
{
    for(unsigned int i=0; i < data->nLoops; i++)
    {
        Mutex::Lock lock = Mutex::Lock(*mutex);
        data -> counter += 1.0;
        lock.~Lock();
    }
}



