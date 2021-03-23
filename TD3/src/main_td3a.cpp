/* =====================================================================================================================
 * main_td3a.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to verify an object chrono
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Chrono.h"
#include "timespec.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>


int main()
{
    struct timespec timeBegin;
    struct timespec timeEnd;
    
    // Initialize the object Chrono
    Chrono chrono;
    timeBegin = timespec_now();
    std::cout << "---Start of test---" << std::endl;
    std::cout << "Sleeping for 5000 ms" << std::endl;
    sleep(5);

    chrono.stop();
    timeEnd = timespec_now();

    // Verify the object Chrono 
    std::cout << "Time measured by TimeSpec :" << (timespec_to_ms(timeEnd-timeBegin)) << "ms" << std::endl;
    std::cout << "Time measured by Chrono :" << chrono.lap() << " ms" << std::endl;
    std::cout << "---End of test---" << std::endl;
    return 0;
}

