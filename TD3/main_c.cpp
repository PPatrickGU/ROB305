/* =====================================================================================================================
 * main_c.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Main function to test calibration
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */


#include "Looper.h"
#include "Calibrator.h"
#include "CpuLoop.h"
#include <iostream>
#include <string>
#include <iomanip> 

int main()
{
	Calibrator calib = Calibrator(1000, 10);
	CpuLoop cpul = CpuLoop(calib);

    // Verification
    std::cout << "\n---Strat of verification---" << std::endl;
	int time = 1000;
    cpul.runTime(time);                     // runtime
    std::cout << "Real number of Loop : " << cpul.getSample()  << std::endl;
    std::cout << "Number of Loop estimated by calib : " <<  calib.nLoops(time) << std::endl;
    std::cout << "Error : " << abs(cpul.getSample() - calib.nLoops(time)) << std::endl;
    std::cout << "Accuracy : " << (1 - (abs(cpul.getSample() - calib.nLoops(time))/cpul.getSample()))*100 << "%" << std::endl;
    std::cout << "---End of verification---" << std::endl;

    return 0;
}
