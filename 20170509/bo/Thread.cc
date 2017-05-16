 ///
 /// @file    Thread.cc
 /// @author  heartinharbin
 /// @date    2017-05-09 21:00:41
 ///

#include "Thread.h"

namespace wd{

Thread::Thread(functionCallback fcb)
: _pthId(0)
, _isRunning(false)
, _fcb(fcb){}


Thread::~Thread(){
	if(_pthId){
		pthread_detach(_pthId);
		_isRunning = false;
	}
}

void Thread::start(){
	pthread_create(&_pthId, NULL, threadFunc, this);
	_isRunning = true;
}

void Thread::join(){
	pthread_join(_pthId, NULL);
	_isRunning = false;
}

void * Thread::threadFunc(void *arg){
	Thread *p = static_cast<Thread*>(arg);
	if(p)
		p->_fcb();
	return NULL;
}

}//end of namespace wd
