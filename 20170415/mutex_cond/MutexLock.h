#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include <pthread.h>
class MutexLock{
public:
	MutexLock();

	~MutexLock();

	bool lock();

	bool unlock();

	bool isLocking();

	pthread_mutex_t * getMutexLockPtr();

private:
	MutexLock(const MutexLock &);
	MutexLock & operator=(const MutexLock &);

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};//end of class MutexLock


//利用找对象来保护资源
//栈对象特点：创建时自动调用构造函数，销毁时自动调用析构函数
class MutexLockGuard{
public:
	MutexLockGuard(MutexLock &); 
	~MutexLockGuard();
private:
	MutexLock & _mutex;
};//end of class MutexLockGuard

#endif
