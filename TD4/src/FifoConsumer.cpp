/* =====================================================================================================================
 * FifoConsumer.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class FifoConsumer
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Thread.h"
#include "FifoConsumer.h"
#include "timespec.h"
#include <pthread.h>
#include <iostream>

FifoConsumer::FifoConsumer(Fifo<int> *fif) : Thread(), fifo(fif), counter(0)
{}

FifoConsumer::~FifoConsumer()
{}

void FifoConsumer::run()
{
	while(isActive)
    {
        try
        {
            fifo->pop(1000);
            counter++;
        }
        catch(const Fifo<int>::EmptyException& e)
        {
            isActive = false;
        }
    }
}

unsigned FifoConsumer::getCounter()
{
    return counter;
}