/* =====================================================================================================================
 * main_a.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to verify whether the threads are working
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "IncrThread.h"
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

        double opThreadTime = 0;
        Chrono chrono;

        // create nTasks threads
        IncrThread* incrThread[nTasks];

        for (unsigned int i=0;i<nTasks;i++)
        {
            incrThread[i] = new IncrThread(&data);
        }

        for (unsigned int i=0;i<nTasks;i++)
        {
            incrThread[i] -> start();
            opThreadTime += incrThread[i]->execTime_ms();
        }

        // join threads
        for (unsigned int i=0;i<nTasks;i++)
        {
            incrThread[i] -> join();
        }
        
        chrono.stop();

        std::cout << "Counter : " <<  (incrThread[0]->data)->counter << std::endl;
        std::cout << "Time taken by all the threads : " << opThreadTime << " ms" << std::endl;
        std::cout << "Execution time of main : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected." << std::endl;
    }

    return 0;
}