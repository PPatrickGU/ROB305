/* =====================================================================================================================
 * main_td4c.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to test Semaphore class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "timespec.h"
#include "Chrono.h"
#include "Semaphore.h"
#include "SemaProducer.h"
#include "SemaConsumer.h"
#include "Mutex.h"
#include <string>
#include <stdio.h> 
#include <signal.h>
#include <iostream>


int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        unsigned nProd = stoi(argv[1]);
        unsigned nCons = stoi(argv[2]);
        unsigned nItems = stoi(argv[3]);

        Semaphore semaphore;
        double opThreadTimeProd = 0;
        double opThreadTimeCons = 0;
        unsigned prod = 0;
        unsigned cons = 0;

        Chrono chrono;
        
        SemaProducer *producer[nProd];
        SemaConsumer *consumer[nCons];

        // Create producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] = new SemaProducer(&semaphore, nItems);
        }

        // Create consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] = new SemaConsumer(&semaphore);
        }

        // Start producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] -> start();
        }

        // Start consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] -> start();
        }

        // Join producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] -> join();
            opThreadTimeProd += producer[i] -> execTime_ms();  
            prod += producer[i] -> getCounter();
        }

        // Join consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] -> join();
            opThreadTimeCons += consumer[i] -> execTime_ms(); 
            cons += consumer[i] -> getCounter();
        }
        
        chrono.stop();

        std::cout << "Number of tokens produced : " << prod << std::endl;
        std::cout << "Number of tokens consumed : " << cons << std::endl;        

        if(prod == cons)
        {
            std::cout << "Result : Number correct \n" << std::endl;
        }
        else
        {
            std::cout << "-----NUMBER ERROR-----\n" << std::endl;
        }

        std::cout << "Time taken by all the producers : " << opThreadTimeProd << " ms" << std::endl;
        std::cout << "Time taken by all the consumers : " << opThreadTimeCons << " ms" << std::endl;
        std::cout << "Execution time of main : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected." << std::endl;
    }

    return 0;
}