/* =====================================================================================================================
 * Calibrator.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a class deriving from PerodicTimer.h.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED

#include "Looper.h"
#include "PeriodicTimer.h"
#include <vector>


class Calibrator : public PeriodicTimer
{
private:
	
	double a; // Parameter a of l(t)=a*t+b
	double b; // Parameter b of l(t)=a*t+b
	std::vector<double> samples; //Vector of samples obtained from different timer
	unsigned int nSamples; 

public:
	Calibrator(double samplingPeriod_ms, unsigned nSamples); // Constructor
	double nLoops(double duration); // Calculate the estimated number of loops 
	Looper looper; 
	

protected:
	void callback(); // Handler function
};

#endif

