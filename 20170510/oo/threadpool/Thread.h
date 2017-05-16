 ///
 /// @file    Thread.h
 /// @author  heartinharbin
 /// @date    2017-05-12 23:53:22
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

	pthread_t getThreadid() const{
		return _pthId;
	}

	bool isRunning() const{
		return _isRunning;
	}

	virtual void run() = 0;
	void start();
	void join();

private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
};//end of class Thread


}//end of namespace wd

#endif
