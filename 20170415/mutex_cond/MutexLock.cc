#ifndef __MUTEXLOCK_CC__
#define __MUTEXLOCK_CC__

#include "MutexLock.h"


MutexLock::MutexLock()
:_isLocking(false){
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock(){ 
	pthread_mutex_destroy(&_mutex);
}

bool MutexLock::lock(){
	if(0 == pthread_mutex_lock(&_mutex)){
		_isLocking = true;
		return true;
	}
	return false;
}

bool MutexLock::unlock(){
	if(0 == pthread_mutex_unlock(&_mutex)){
		_isLocking = false;
		return true;
	}
	return false;
}

bool MutexLock::isLocking(){
	return _isLocking;
}

pthread_mutex_t * MutexLock::getMutexLockPtr(){
	return &_mutex;
}


MutexLockGuard::MutexLockGuard(MutexLock & mutex) 
:_mutex(mutex){
	_mutex.lock();
}
MutexLockGuard::~MutexLockGuard(){
	_mutex.unlock();
}
#endif

#if 1
#include <iostream>
#include <unistd.h>
using std::cout;
using std::endl;

int num = 0;

void * func1(void *arg){
	MutexLock *p =  static_cast<MutexLock*>(arg);
	while(true){
	//	MutexLockGuard guard(*p);
		p->lock();
		++num;
		cout << "thread " << pthread_self() << ": num = " << num << endl;
		sleep(1);
		p->unlock();
	}
	return NULL;
  
}



int main(void){
	MutexLock mutex;

	pthread_t pth1;
	pthread_t pth2;
	pthread_create(&pth1, NULL, func1, &mutex);
	pthread_create(&pth2, NULL, func1, &mutex);

	cout << "pth1 = " << pth1 << endl;
	cout << "pth2 = " << pth2 << endl;

	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	return 0;
}
#endif





