/* =====================================================================================================================
 * Calibrator.cpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Implement the Calibrator class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#include "Calibrator.h"
#include <vector>
#include <iostream>

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples) : nSamples(nSamples)
{
	std::cout << "---Start of calibration:---"  << std::endl; 
	start(samplingPeriod_ms);
	looper.runLoop();

	stop();

	// Linear regression formula: sum_x, sum_y, sum_xx(x^2), sum_xy
	// x = nSamples * * samplingPeriod_ms, y = samples[i]
	long double sum_x = nSamples * (nSamples + 1) / 2 * samplingPeriod_ms;  // x(x+1)/2
	long double sum_xx = nSamples * (nSamples + 1) * (2 * nSamples + 1) / 6 * samplingPeriod_ms * samplingPeriod_ms; // x(x+1)(2x+1)/6
	long double sum_y=0;
	long double sum_xy = 0;
	for (unsigned int i=0; i< nSamples; i++)
	{
		sum_y += samples[i];
		sum_xy += ((i + 1) * samplingPeriod_ms) * samples[i]; // x*y
	}
	a = (double) (nSamples * sum_xy - sum_x * sum_y) / (nSamples * sum_xx - sum_x * sum_x);
	b = (double) sum_y / nSamples - a * sum_x / nSamples;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "test : " << nLoops(samplingPeriod_ms) << std::endl;

	std::cout << "---End of calibration---"  << std::endl; 
}

void Calibrator::callback()
{
	double sample = looper.getSample();
	std::cout << "Sample value : " << sample << std::endl;
	samples.push_back(sample);
	if (samples.size() == nSamples) 
	{
		looper.stopLoop();
		std::cout << "----STOPPING----" << std::endl;
	}
}

double Calibrator::nLoops(double duration_ms)
{
	return (a * duration_ms + b);
}


