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
	
/*
	MutexLock(pthread_mutex_t mutex)
	:m_mutex(mutex){
		pthread_mutex_init(&m_mutex, NULL);
	}


	MutexLock(pthread_mutex_t mutex, pthread_mutexattr_t mutexattr)
	:m_mutex(mutex)
	,m_mutexattr(mutexattr){
		pthread_mutex_init(&m_mutex, &m_mutexattr);
	}
*/
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

int a = 0;
int b = 0;
pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void * func(void *){
	pthread_mutex_lock(&mutex_b);
	cout << "child  get mutex_b,wait for mutex_a" << endl;
	sleep(3);
	++b;
	pthread_mutex_lock(&mutex_a);
	cout << "child get mutex_a and mutex_b" << endl;
	b += a;
	pthread_mutex_unlock(&mutex_a);
	pthread_mutex_unlock(&mutex_b);
	pthread_exit(NULL);
}


int main(){
	pthread_t pid;
	
	pthread_mutex_init(&mutex_a, NULL);
	pthread_mutex_init(&mutex_b, NULL);

	pthread_create(&pid, NULL, func, NULL);	
	
	pthread_mutex_lock(&mutex_a);
	cout << "main get mutex_a wait for mutex_b" << endl;
	sleep(3);
	++a;
	pthread_mutex_lock(&mutex_b);
	cout << "main get mutex_a  and mutex_b" << endl;
	a += b;
	pthread_mutex_unlock(&mutex_b);
	pthread_mutex_unlock(&mutex_a);

	pthread_join(pid, NULL);
	pthread_mutex_destroy(&mutex_a);
	pthread_mutex_destroy(&mutex_b);
	return 0;
}







