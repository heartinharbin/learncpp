 ///
 /// @file    Thread.cc
 /// @author  heartinharbin
 /// @date    2017-05-09 21:00:41
 ///

#include "Thread.h"

namespace wd{

Thread::Thread()
: _pthId(0)
, _isRunning(false){}


Thread::~Thread(){
	if(_pthId){
		pthread_detach(_pthId);
		_isRunning = false;
	}
}

void Thread::start(){
	pthread_create(&_pthId, NULL, ThreadFunc, this);
	_isRunning = true;
}

void Thread::join(){
	pthread_join(_pthId, NULL);
	_isRunning = false;
}

void * Thread::ThreadFunc(void * arg){
	Thread * p = static_cast<Thread*>(arg);
	if(p)
		p->run();
	return NULL;
}

}//end of namespace wd
