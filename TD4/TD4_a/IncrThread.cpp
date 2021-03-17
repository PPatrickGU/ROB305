/* =====================================================================================================================
 * IncrThread.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implements the class IncrThread 
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "IncrThread.h"
#include <iostream>

IncrThread::IncrThread(Data* data): Thread(), data(data)
{
	int priority = rand()%99 + 1;       //I get a number between 1 and 100
    int schedPriority = data->schedPolicy == SCHED_OTHER ? 0 : priority;
    setScheduling(data->schedPolicy, schedPriority);
}

IncrThread::~IncrThread()
{}

void IncrThread::run()
{
    for(unsigned int i=0; i < data->nLoops; i++)
    {
        data -> counter += 1.0;
    }
}



