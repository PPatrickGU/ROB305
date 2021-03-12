/* =====================================================================================================================
 * main_b.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to create veridy an object countdown
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "timespec.h"
#include "CountDown.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip> 


int main()
{
    //verifying countdown
    CountDown countDown(10);
    countDown.start(200);

    while (countDown.getCount() > 0){}

    return 0;
}