 ///
 /// @file    Thread.h
 /// @author  heartinharbin
 /// @date    2017-05-09 20:46:54
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
namespace wd{

class Thread
: Noncopyable{
	typedef std::function<void()> functionCallback;
public:
	Thread(functionCallback);
	~Thread();
	
	void start();
	void join();
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
	functionCallback _fcb;
};//end of class Thread

}//end of namespace wd

#endif
