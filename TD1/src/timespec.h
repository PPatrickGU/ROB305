/* =====================================================================================================================
 * timespec.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines a timespec class
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef timespec_h_INCLUDED
#define timespec_h_INCLUDED

#include <time.h>
#include <cerrno>

// Transformation from timespec (seconds and nanoseconds) to seconds
double timespec_to_ms(const timespec& time_ts);

// Transformation from ms to timespec
timespec timespec_from_ms(double time_ms);

// Get the current time
timespec timespec_now();

// Negate the timespec time
timespec timespec_negate(const timespec& time_ts);

// Add two timespec
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

// Subtract two timespec
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

// Wait for a time (timespec)
timespec timespec_wait(const timespec& delay_ts);

// Polymorphism of the operator negation
timespec  operator- (const timespec& time_ts);

// Polymorphism of the operator addition +
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

// Polymorphism of the operator subtraction -
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

// Polymorphism of the operator add +=
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

// Polymorphism of the operator subtraction -=
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

// Polymorphism of the bigger condition ==
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

// Polymorphism of the notequal condition !=
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

// Polymorphism of the smaller condition <
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

// Polymorphism of the bigger condition >
bool operator> (const timespec& time1_ts, const timespec& time2_ts);


#endif
