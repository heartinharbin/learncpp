 ///
 /// @file    MutexLock.cc
 /// @author  heartinharbin
 /// @date    2017-04-12 21:04:04
 ///
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

MutexLock mutex;

void * func(void *){
	cout << "child thread: lock the mutex" << endl;
	mutex.lock();
	sleep(3);
	mutex.unlock();
	cout << "child thread: unlock the mutex" << endl;
}

void prepare(){
	mutex.lock();
}

void infork(){
	mutex.unlock();
}


int main(){
	pthread_t id;
	pthread_create(&id, NULL , func, NULL);
	sleep(1);
	pthread_atfork(prepare, infork, infork);
	int pid = fork();
	if(pid < 0){
		pthread_join(id, NULL);
		return 1;
	}else if(0 == pid){
		printf("i am in the child, want to get the lock\n");
		mutex.lock();
		sleep(1);
		printf("i can not run to here\n");
		mutex.unlock();
		exit(0);
	}else{
		wait(NULL);
	}
	pthread_join(id, NULL);
	return 0;
}







