 ///
 /// @file    MutexLock.cc
 /// @author  heartinharbin
 /// @date    2017-04-12 21:04:04
 ///
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

class MutexLock{
public:
	MutexLock(pthread_mutexattr_t mutexattr)
	:m_mutexattr(mutexattr){
		pthread_mutex_init(&m_mutex, &m_mutexattr);
	}

	MutexLock(){
		pthread_mutex_init(&m_mutex, NULL);
	}



	~MutexLock(){
		pthread_mutex_destroy(&m_mutex);
	}

	bool lock(){
		return pthread_mutex_lock(&m_mutex) == 0;
	}

	bool unlock(){
		return pthread_mutex_unlock(&m_mutex) == 0;
	}
private:
	pthread_mutex_t m_mutex;
	pthread_mutexattr_t m_mutexattr;
};//end of class MutexLock



class Condition{
public:
	Condition(){
		cout << "Condition()"  << endl;
		if(pthread_mutex_init(&c_mutex, NULL) != 0){
			cout << "pthread_mutex_init" << endl;
		}
		if(pthread_cond_init(&c_cond, NULL) != 0){
			pthread_mutex_destroy(&c_mutex);
			cout << "pthread_cond_init" << endl;
		}
	}
	~Condition(){
		cout << "~Condition()"  << endl;
		pthread_mutex_destroy(&c_mutex);
		pthread_cond_destroy(&c_cond);
	}
	bool wait(){
		int ret = 0;
		pthread_mutex_lock(&c_mutex);
		ret = pthread_cond_wait(&c_cond, &c_mutex);
		pthread_mutex_unlock(&c_mutex);
		return ret == 0;
	}
	bool notify(){
		return pthread_cond_signal(&c_cond) == 0;
	}
	bool notifyall(){
		return pthread_cond_broadcast(&c_cond) == 0;
	}
private:
	pthread_mutex_t c_mutex;
	pthread_cond_t c_cond;
};//end of class Condition







Condition cond;

void * func(void *){
	printf("pthreat:i will wait\n");
	cond.wait();
	printf("pthread:i am wakeup\n");
	pthread_exit((void*)5);
}


int main(){
	pthread_t pthid;
	bool bret;
	int ret;
	ret = pthread_create(&pthid, NULL, func, NULL);
	if(ret != 0){
		printf("pthread_create() error\n");
		return -1;
	}
	sleep(3);
	printf("I am in main thread!\n");
	bret = cond.notify();
	if(!bret){
		printf("cond.notify()\n");
	}
	long threadret;
	ret = pthread_join(pthid, (void**)&threadret);
	if(ret != 0){
		printf("pthread_join() error\n");
		return -1;
	}
	return 0;
}







