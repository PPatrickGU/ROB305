/* =====================================================================================================================
 * main_c.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to realize the increment without using signal
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include <unistd.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "timespec.h"

void incr(unsigned int nLoops, double* pCounter)
{
    for(unsigned int iLoop = 0; iLoop < nLoops; ++iLoop)
    {
        *pCounter += 1.0;
    }
}

int main(int argc, char* argv[])
{
    unsigned int nLoops = std::stoul(argv[1], NULL, 10);
    double counter = 0.0;
   	struct timespec time_begin, time_end;

    time_begin = timespec_now();
    incr(nLoops, &counter);          
    time_end = timespec_now();

    std::cout << "Counter value: " << counter << std::endl;    
    std::cout << std::fixed << std::setprecision(9) << "Time needed: " << (timespec_to_ms(time_end - time_begin)/1000) << " seconds" <<std::endl; 
    return 0;
}
