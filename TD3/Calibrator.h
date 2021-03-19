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
	
	// Parameter a of l(t)=a*t+b
	double a; 

	// Parameter b of l(t)=a*t+b
	double b; 

	//Vector of samples obtained from different timer
	std::vector<double> samples; 

	unsigned int nSamples; 

public:
	// Constructor
	Calibrator(double samplingPeriod_ms, unsigned nSamples); 

	// Calculate the estimated number of loops 
	double nLoops(double duration); 

	Looper looper; 
	

protected:
	// Handler function
	void callback(); 
};

#endif

