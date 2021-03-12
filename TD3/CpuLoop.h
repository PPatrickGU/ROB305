/* =====================================================================================================================
 * Calibrator.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class CpuLooper deriving from Looper which will make a calibration given a time.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef CpuLoop_h_INCLUDED
#define CpuLoop_h_INCLUDED

#include "Calibrator.h"
#include "Looper.h"

class CpuLoop : public Looper
{
private:
	// Reference on a calibrator object
	Calibrator& calibrator;

public:
	// Constructor
	CpuLoop(Calibrator& calibrator);
	// Run the Looper objet with a given time
	void runTime(double duration_ms);
};

#endif

