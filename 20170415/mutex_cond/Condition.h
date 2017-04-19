 ///
 /// @file    Condition.h
 /// @author  heartinharbin
 /// @date    2017-04-17 22:34:36
 ///


#ifndef __CONDITION_H__
#define __CONDITION_H__

#include <pthread.h>

class MutexLock; //类的前向声明

class Condition{
public:
	Condition(MutexLock &);
	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};//end of class Condition

#endif
