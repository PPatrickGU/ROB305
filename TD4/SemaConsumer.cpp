/* =====================================================================================================================
 * SemaConsumer.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class SemaConsumer
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Thread.h"
#include "SemaConsumer.h"
#include "timespec.h"
#include <pthread.h>
#include <iostream>

SemaConsumer::SemaConsumer(Semaphore *sema) : Thread(), semaphore(sema), counter(0)
{}

SemaConsumer::~SemaConsumer()
{}

void SemaConsumer::run()
{
    while(semaphore->take(100))
    {
        counter++;
    }
}

unsigned SemaConsumer::getCounter()
{
    return counter;
}