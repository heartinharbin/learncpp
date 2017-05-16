 ///
 /// @file    ThreadpoolThread.h
 /// @author  heartinharbin
 /// @date    2017-05-13 14:44:35
 ///

#ifndef __WD_THREADPOOL_THRAED_H__
#define __WD_THREADPOOL_THRAED_H__

#include "Thread.h"
#include "Threadpool.h"
#include <iostream>

using std::cout;
using std::endl;

namespace wd{

class ThreadpoolThread
: public Thread{
public:
	ThreadpoolThread(Threadpool & threadpool)
	: _threadpool(threadpool){}

	void run(){
		_threadpool.threadFunc();
	}

	~ThreadpoolThread(){
		cout << "~ThreadpoolThread()" << endl;
	}
private:
	Threadpool & _threadpool;
};//end of class ThreadpoolThread

}//end of namespace wd

#endif
