/* =====================================================================================================================
 * Fifo.hpp
 * ---------------------------------------------------------------------------------------------------------------------
 * Defines Fifo class template
 * @author Zhaoyi Guan & Dajing Gu
 * =====================================================================================================================
*/

#ifndef Fifo_hpp_INCLUDED
#define Fifo_hpp_INCLUDED

#include "Mutex.h"
#include <queue>
#include <exception>
#include <string>


template <typename T> class Fifo
{
private:
	// Elements in the fifo
	std::queue<T> elements;

	// Mutex element
	Mutex mutex;

public:
	// Exception if the fifo is empty
	class EmptyException : std::exception
	{
		public:
			const char* throwException() const noexcept;
	};	

	// Add an element at the end of queue
	void push(T element);

	// Remove the element at the top of the queue
	T pop();

	// Remove the element at the top of the queue with a timeout
	T pop(double timeout_ms);
};


template <typename T> void Fifo<T>::push(T element)
{
	Mutex::Lock lock(mutex);
	elements.push(element);
	lock.notify();
	lock.~Lock();
}

template <typename T> T Fifo<T>::pop()
{	
	T popped = elements.front();
	Mutex::Lock lock(mutex);
	if (elements.empty()) // blocked if fifo is empty
	{
		lock.wait();
	}
	else
	{
		elements.pop();
	}	
	lock.notify();
    lock.~Lock();
	return popped;
}

template <typename T> T Fifo<T>::pop(double timeout_ms)
{	
	T popped = elements.front();
	Mutex::Lock lock(mutex); 
	if (elements.empty())  // blcoked if fifo is empty
	{
		throw Fifo<T>::EmptyException();
		lock.wait(timeout_ms);
		lock.notify();
        lock.~Lock();
    }    
	else
	{
		elements.pop();
		lock.notify();
        lock.~Lock();
	}
	return popped;
}

template <typename T> const char *Fifo<T>::EmptyException::throwException() const noexcept
{
		return "Empty exception!\n";
}

#endif
