 ///
 /// @file    Condition.cc
 /// @author  heartinharbin
 /// @date    2017-05-12 20:33:24
 ///
#include "MutexLock.h"
#include "Condition.h"
namespace wd{

Condition::Condition(MutexLock & mutex)
: _mutex(mutex){
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition(){
	pthread_cond_destroy(&_cond);
}

void Condition::wait(){
	pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
}

void Condition::notify(){
	pthread_cond_signal(&_cond);
}

void Condition::notifyall(){
	pthread_cond_broadcast(&_cond);
}
}//end of namesapce wd
