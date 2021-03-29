/* =====================================================================================================================
 * main_td1a.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to verify an object timespec
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */


#include <unistd.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "timespec.h"

 
int main() 
{ 
	std::cout << "Strat testing:" << std::endl;

	// Test timespec_now();
	std::cout << "\n" << "Test timespec_now():" <<std::endl;
	struct timespec time_now;
	time_now = timespec_now();
	std::cout << "Secondes:" << time_now .tv_sec << ", Nanosec: " << time_now.tv_nsec << std::endl;

	// Test timespec_negate();
	std::cout << "\n" << "Test timespec_negate():" <<std::endl;
	struct timespec time_neg;
	time_neg = timespec_negate(time_now);
	std::cout << "Secondes:" << time_neg .tv_sec << ", Nanosec: " << time_neg.tv_nsec << std::endl;

	// Test timespec_to_ms
	double time_to_ms;
	std::cout << "\n" << "Test timespec_to_ms:" <<std::endl;
	time_to_ms = timespec_to_ms(time_now);
	std::cout << "Millisec:" << time_to_ms << "ms" << std::endl;

	// Test timespec_from_ms
	std::cout << "\n" << "Test timespec_from_ms:" <<std::endl;
	struct timespec time_from_ms;
	time_from_ms = timespec_from_ms(time_to_ms);
	std::cout << "Secondes:" << time_from_ms.tv_sec << ", Nanosec: " << time_from_ms.tv_nsec << std::endl;

	// Test timespec_add
	std::cout << "\n" << "Test timespec_add (origin + negate):" <<std::endl;
	struct timespec time_add;
	time_add = timespec_add(time_now, time_neg);
	std::cout << "Secondes:" << time_add.tv_sec << ", Nanosec: " << time_add.tv_nsec << std::endl;

	// Test timespec_sub
	std::cout << "\n" << "Test timespec_sub:" <<std::endl;
	struct timespec time_sub;
	time_sub = timespec_subtract(time_now, time_now);
	std::cout << "Secondes:" << time_sub.tv_sec << ", Nanosec: " << time_sub.tv_nsec << std::endl;

	// Test timespec_wait
	std::cout << "\n" << "Test timespec_wait:" <<std::endl;
	struct timespec delay_ts, time_rem;
    delay_ts.tv_nsec = 500000000;    // 1500ms
    delay_ts.tv_sec = 1;

   	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
	std::cout << "Start time: " << "Secondes:" << start.tv_sec << ", Nanosec: " << start.tv_nsec << std::endl;
	time_rem = timespec_wait(delay_ts);
	clock_gettime(CLOCK_REALTIME, &end);
	std::cout << "End time: "<< "Secondes:" << end.tv_sec << ", Nanosec: " << end.tv_nsec << std::endl;

	
	//Test operators
	struct timespec time1, time2;
    time1.tv_nsec = 500000000;    
    time1.tv_sec = 10;

    time2.tv_nsec = 0;    
    time2.tv_sec = 5;

    std::cout << "\n\nStart testing operators \n" << std::endl;
    std::cout << "time1: "<< "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << std::endl;
    std::cout << "time2: "<< "Secondes:" << time2.tv_sec << ", Nanosec: " << time2.tv_nsec << std::endl;
    
    //test operator-
    std::cout << "\n" << "Test operator-:" <<std::endl;
    struct timespec time1_neg;
    time1_neg = -time1;
	std::cout << "-time1: "<< "Secondes:" << time1_neg.tv_sec << ", Nanosec: " << time1_neg.tv_nsec << std::endl;  
    
    //test operator+
    std::cout << "\n" << "Test operator+:" <<std::endl;
    time_add = time1 + time2;
	std::cout << "time1 + time2: "<< "Secondes:" << time_add.tv_sec << ", Nanosec: " << time_add.tv_nsec << std::endl;     
    
    //test operator-
    std::cout << "\n" << "Test operator-:" <<std::endl;
    time_sub = time1 - time2;
	std::cout << "time1 - time2: "<< "Secondes:" << time_sub.tv_sec << ", Nanosec: " << time_sub.tv_nsec << std::endl;     
 
    //test operator+=
    std::cout << "\n" << "Test operator+=:" <<std::endl;
    time1 += time2;
	std::cout << "time1 += time2: "<< "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << std::endl;  

    //test operator-=
    std::cout << "\n" << "Test operator-=:" <<std::endl;
    time1 -= time2;
	std::cout << "time1 -= time2: "<< "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << std::endl; 
 

    //test operator==
    std::cout << "\n" << "Test operator==:" <<std::endl;
	std::cout << "time1==time1 " << (time1==time1) <<  std::endl; 
	std::cout << "time1==time2 " << (time1==time2) <<  std::endl; 
    
    //test operator!=
    std::cout << "\n" << "Test operator!=:" <<std::endl;
	std::cout << "time1!=time1 " << (time1!=time1) <<  std::endl; 
	std::cout << "time1!=time2 " << (time1!=time2) <<  std::endl; 

	//test operator<
    std::cout << "\n" << "Test operator<:" <<std::endl;
	std::cout << "time1<time2 " << (time1<time2) <<  std::endl; 
	std::cout << "time2<time1 " << (time2<time1) <<  std::endl; 

	//test operator>
    std::cout << "\n" << "Test operator>:" <<std::endl;
	std::cout << "time1>time2 " << (time1>time2) <<  std::endl; 
	std::cout << "time2>time1 " << (time2>time1) <<  std::endl; 

	std::cout << "\nEnd testing" << std::endl;
    
    return 0;
}
