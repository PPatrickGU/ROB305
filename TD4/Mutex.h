/* =====================================================================================================================
 * Mutex.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the Mutex class which encapsulates the functionalities of a posix mutex
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */


#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED

#include <pthread.h>
#include <exception>

class Mutex
{
public :
  	// Class that locks a mutex
	class Lock;

	// Class that tries to lock a mutex
	class TryLock;

	// Class that monitors a mutex
	class Monitor;
		
	// Constructor of Mutex
	Mutex();

	// Destructor of Mutex
	~Mutex();

private :
	// Posix mustex
	pthread_mutex_t posixId; 

	// Posix condition attribute of the mutex
	pthread_cond_t posixCondId;
	
	// Lock the mutex
	void lock();

	// Lock with a timeout
	bool lock(double timeout_ms);

	// Try to lock the mutex
	bool trylock();

	// Unlock the mutex
	void unlock();
};

class Mutex::Monitor
{
public :
    	// Throws an exception when Lock does not work.
	class TimeoutException;

	// Wait for the posix condition of the mutex
	void wait();

	// Wait for the posix condition of the mutex or the end of a duration
	bool wait(double timeout_ms);

	// Unlock a thread that is in blocked in a waiting condition
	void notify();

	// Unlock all the threads that are blocked in a waiting condition
	void notifyAll();

	// Reference to a Mutex object
	Mutex& mutex; 

protected :
	// Constructor of Mutex::Monitor class.
	Monitor(Mutex& m);
};

class Mutex::Monitor::TimeoutException
{
public:
	const char* launchingException() const noexcept;
};

class Mutex::Lock : public Mutex::Monitor
{
public :
	// Constructor
	Lock(Mutex& m);

    	// Constructor with a timeout 
	Lock(Mutex& m, double timeout_ms);

	//Destructor
	~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
public :
	// Constructor
	TryLock(Mutex& m);
	
	//Destructor
	~TryLock();
};

#endif
