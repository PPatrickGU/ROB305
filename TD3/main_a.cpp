#include "Chrono.h"
#include "timespec.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

int main()
{
    struct timespec timeBegin;
    struct timespec timeEnd;
    
    // Initialize the object Chrono
    Chrono chrono;
    timeBegin = timespec_now();
    cout << "Sleeping for 5000 ms" << endl;
    sleep(5);

    chrono.stop();
    timeEnd = timespec_now();

    // Verify the object Chrono 
    std::cout << "Time measured by TimeSpec is " << (timespec_to_ms(timeEnd-timeBegin)) << "ms" << std::endl;
    std::cout << "Time measured by Chrono is " << chrono.lap() << " ms" << std::endl;
    return 0;
}

