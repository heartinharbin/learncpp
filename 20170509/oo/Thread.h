 ///
 /// @file    Thread.h
 /// @author  heartinharbin
 /// @date    2017-05-09 20:46:54
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd{

class Thread
: Noncopyable{
public:
	Thread();
	~Thread();
	
	virtual void run() = 0;
	void start();
	void join();
private:
	static void * ThreadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
};//end of class Thread

}//end of namespace wd

#endif
