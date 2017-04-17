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

int a = 0;
int b = 0;
MutexLock mutex_a;
MutexLock mutex_b;

void * func(void *){
	mutex_b.lock();
	cout << "child  get mutex_b,wait for mutex_a" << endl;
	sleep(3);
	++b;
	mutex_a.lock();
	cout << "child get mutex_a and mutex_b" << endl;
	b += a;
	mutex_a.unlock();
	mutex_b.unlock();
	pthread_exit(NULL);
}


int main(){
	pthread_t pid;
		
	pthread_create(&pid, NULL, func, NULL);	
	
	mutex_a.lock();
	cout << "main get mutex_a wait for mutex_b" << endl;
	sleep(3);
	++a;
	mutex_b.lock();
	cout << "main get mutex_a  and mutex_b" << endl;
	a += b;
	mutex_b.unlock();
	mutex_a.unlock();

	pthread_join(pid, NULL);
	return 0;
}







