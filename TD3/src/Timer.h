/* =====================================================================================================================
 * Timer.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a class implementing a posix timer.
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

#include <time.h>
#include <signal.h>

class Timer
{
public:
	Timer();
	~Timer();	
	
	void start(double duration_ms);
	void stop();

protected:
	timer_t timerId;
	// it is pure virtual since it will be different in each different time
	virtual void callback() = 0;

private:
	// call the handler function
	static void call_callback(int, siginfo_t* si, void*); 
};


#endif
