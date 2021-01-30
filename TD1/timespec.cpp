#include "timespec.h"
#include <math.h>
#include <cerrno>

double timespec_to_ms(const timespec& time_ts)
{ 	
	double time_ms = 0.0;
    time_ms = time_ts.tv_sec*1e3 + time_ts.tv_nsec/1e6;
    return time_ms;               
}

timespec timespec_from_ms(double time_ms)
{
    timespec time_ts;
    time_ts.tv_sec = (time_ms >= 0) ? time_ms/1e3 : time_ms/1e3-1;  
    time_ts.tv_nsec = (time_ms - time_ts.tv_sec*1e3) * 1e6;         
    return time_ts; 
}

timespec timespec_now()
{
	timespec time_now;
	clock_gettime(CLOCK_REALTIME, &now);
	return time_now;
}

timespec timespec_negate(const timespec& time_ts)
{
    timespec time_neg;
    time_neg.tv_nsec = 1e9 - time_ts.tv_nsec;                                       
    time_neg.tv_sec = -time_ts.tv_sec - 1;                      
    return time_neg;
}

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_add;
    time_add.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;   
    time_add.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec; 
    if (time_add.tv_nsec >= 1e9)
    {
    	time_add.tv_nsec -= 1e9;
    	time_add.tv_sec += 1;
    }                                                      
    return time_add;
}

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_sub;
    time_sub.tv_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;   
    time_sub.tv_sec = time1_ts.tv_sec - time2_ts.tv_sec; 
    if (time_sub.tv_nsec < 0)
    {
    	time_sub.tv_nsec += 1e9;
    	time_sub.tv_sec -= 1;
    }                                                      
    return time_sub;
}

timespec timespec_wait(const timespec& delay_ts)
{	
	timespec time_start, time_stop, time_duration;
	clock_gettime(CLOCK_REALTIME, time_start);
	nanosleep(1000);
	clock_gettime(CLOCK_REALTIME, &fin);

	clock_gettime(CLOCK_REALTIME, &fin);
}

timespec timespec_wait(const timespec& delay_ts)
{
    timespec rem_ts;                                      
    if(nanosleep(&delay_ts, &rem_ts) == -1)                    
    {
        if(errno == EINTR)
        {
            timespec_wait(rem_ts);
        }
    }
    return rem_ts;
}

timespec  operator- (const timespec& time_ts)                    
{
    return timespec_negate(time_ts);
}

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)    
{
    return timespec_add(time1_ts, time2_ts);
}

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)   
{
    return timespec_subtract(time1_ts, time2_ts);
}

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)        
{
    time_ts = timespec_add(time_ts, delay_ts);
    return time_ts;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)          
{
    time_ts = timespec_subtract(time_ts, delay_ts); 
    return time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts)        
{
    return (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)        
{
    return (time1_ts.tv_sec != time2_ts.tv_sec || time1_ts.tv_nsec != time2_ts.tv_nsec);
}

bool operator< (const timespec& time1_ts, const timespec& time2_ts)        
{
    return (time1_ts.tv_sec < time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec < time2_ts.tv_nsec));
}

bool operator> (const timespec& time1_ts, const timespec& time2_ts)       
{
    return (time1_ts.tv_sec > time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec > time2_ts.tv_nsec));
}
