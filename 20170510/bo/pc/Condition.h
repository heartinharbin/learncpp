 ///
 /// @file    Condition.h
 /// @author  heartinharbin
 /// @date    2017-05-12 20:26:48
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd{

class MutexLock;//前向声明

class Condition
: Noncopyable{
public:
	Condition(MutexLock &);
	~Condition();
	void wait();
	void notify();
	void notifyall();
private:
	MutexLock & _mutex;
	pthread_cond_t _cond;
};//end of class Condition
}//end of namespace wd

#endif
