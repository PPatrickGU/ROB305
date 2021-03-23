/* =====================================================================================================================
 * SemaProducer.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class SemaProducer 
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Thread.h"
#include "SemaProducer.h"
#include "timespec.h"
#include <pthread.h>
#include <iostream>

SemaProducer::SemaProducer(Semaphore *sema, unsigned maxNum) : Thread(), semaphore(sema), counter(0), maxCount(maxNum)
{}

SemaProducer::~SemaProducer()
{}

void SemaProducer::run()
{
    for(unsigned i = 0; i < maxCount; i++)
    {
    	semaphore -> give();
    	counter++;
    }
}

unsigned SemaProducer::getCounter()
{
    return counter;
}