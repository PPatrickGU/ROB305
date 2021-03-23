/* =====================================================================================================================
 * PosixThread.h
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines the class PosixThread which implements the basic functions of a Thread Posix
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
 */

#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED

#include <pthread.h>
#include <exception>

using namespace std;

class PosixThread
{
public:
	
	PosixThread(); 
	// Constructor

	PosixThread(pthread_t posixId); 
	//Constructor based on the Id of existing thread

	~PosixThread();

	void start(void*(*threadFunc)(void*), void* threadArg); 
	// Start the thread
	
	void join(); 
	// Terminate the thread
	
	bool join(double timeout_ms); 
	// Terminate the thread with a timeout

	bool setScheduling(int schedPolicy, int priority); 
	// Set the scheduling of the thread
	
	bool getScheduling(int* pSchedPolicy, int* pPriority); 
	// Get the scheduling of the thread

	class Exception; 

private:
	pthread_t posixId; 
	// Posix thread 
	pthread_attr_t posixAttr; 
	//Posix attribute

protected:
	bool isActive = false; 
	// true if the task is active
};


class PosixThread::Exception : public exception
{
public:		
	const char* launchingException() const noexcept;
};


#endif


