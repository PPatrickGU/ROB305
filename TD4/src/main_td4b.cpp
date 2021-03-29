/* =====================================================================================================================
 * main_td4b.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to verify whether the Mutex works
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "IncrMutexThread.h"
#include "Mutex.h"
#include "timespec.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h> 
#include <pthread.h>
#include "Chrono.h"


int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        unsigned int nLoops = std::stoi(argv[1]);
        unsigned int nTasks = std::stoi(argv[2]);

        int schedPolicy;
        if(string(argv[3]) == "SCHED_RR") schedPolicy = SCHED_RR;           
        else if(string(argv[3]) == "SCHED_FIFO") schedPolicy = SCHED_FIFO;      
        else schedPolicy = SCHED_OTHER;

        Data data = {nLoops, 0.0, schedPolicy};
        Mutex mutex;

        double opThreadTime = 0;
        Chrono chrono;

        // create nTasks threads
        IncrMutexThread *incrMutexThread[nTasks];

        for (unsigned int i=0;i<nTasks;i++)
        {
            incrMutexThread[i] = new IncrMutexThread(&data, &mutex);
        }

        for (unsigned int i=0;i<nTasks;i++)
        {
            incrMutexThread[i] -> start();
            opThreadTime += incrMutexThread[i]->execTime_ms();
        }

        // join threads
        for (unsigned int i=0;i<nTasks;i++)
        {
            incrMutexThread[i] -> join();
        }
        
        chrono.stop();

        std::cout << "Counter : " <<  (incrMutexThread[0]->data)->counter << std::endl;
        std::cout << "Time taken by all the threads : " << opThreadTime << " ms" << std::endl;
        std::cout << "Execution time of main : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected : <nLoops> <nTasks> <schedPolicy>" << std::endl;
    }

    return 0;
}