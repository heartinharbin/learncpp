 ///
 /// @file    MutexLock.h
 /// @author  heartinharbin
 /// @date    2017-05-11 09:46:41
 ///
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>
namespace wd{

class MutexLock
: Noncopyable{

public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
	
	pthread_mutex_t * getMutexLockPtr();
private:
	pthread_mutex_t _mutex;
};//end of class MutexLock


class MutexLockGuard{
public:
	MutexLockGuard(MutexLock& mutex)
	: _mutex(mutex){
		_mutex.lock();
	}

	~MutexLockGuard(){
		_mutex.unlock();
	}
private:
	MutexLock &_mutex;
};//end of class MutexLockGuard

}//end of namespace wd
#endif
