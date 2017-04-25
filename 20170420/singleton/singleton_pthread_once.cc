 ///
 /// @file    singleton_nest.cc
 /// @author  heartinharbin
 /// @date    2017-04-20 21:20:57
 ///
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton * getInstance(){
		pthread_once(&_once, init);
		return _pInstance;
	}
	
	static void init(){
		_pInstance = new Singleton;
		atexit(destroy);
	}

	static void destroy(){
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}

private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
}; // end of class Singleton

Singleton * Singleton::_pInstance = getInstance();
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}





