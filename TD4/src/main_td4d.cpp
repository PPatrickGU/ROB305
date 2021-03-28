/* =====================================================================================================================
 * main_td4d.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to test Fifo class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "timespec.h"
#include "Chrono.h"
#include "Fifo.hpp"
#include "FifoProducer.h"
#include "FifoConsumer.h"
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

        Fifo<int> fifo;
        double opThreadTimeProd = 0;
        double opThreadTimeCons = 0;
        unsigned prod = 0;
        unsigned cons = 0;

        Chrono chrono;
        
        FifoProducer *producer[nProd];
        FifoConsumer *consumer[nCons];

        // Create producers
        for (unsigned int i=0; i<nProd; i++)
        {
            producer[i] = new FifoProducer(&fifo, nItems);
        }

        // Create consumers
        for (unsigned int i=0; i<nCons; i++)
        {
            consumer[i] = new FifoConsumer(&fifo);
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
            std::cout << "\nResult : Number CORRECT\n" << std::endl;
        }
        else
        {
            std::cout << "\nResult : Number ERROR\n" << std::endl;
        }

        std::cout << "Time taken by all the producers : " << opThreadTimeProd << " ms" << std::endl;
        std::cout << "Time taken by all the consumers : " << opThreadTimeCons << " ms" << std::endl;
        std::cout << "Execution time of main : " << chrono.lap() << "ms" << std::endl;

    }
    else
    {
        std::cout << "Error: number of arguments. 3 expected : <nProd> <nCons> <nItems>" << std::endl;
    }

    return 0;
}