/* =====================================================================================================================
 * Chrono.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a Chrono classe
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef Chrono_h_INCLUDED
#define Chrono_h_INCLUDED

#include <time.h>

class Chrono
{
private:
	timespec startTime_;
	timespec stopTime_;

public:
	Chrono();
	void stop();			
	void restart();
	bool isActive();
	double startTime();		
	double stopTime();
	double lap();
};

#endif
