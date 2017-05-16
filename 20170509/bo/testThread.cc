 ///
 /// @file    testThread.cc
 /// @author  heartinharbin
 /// @date    2017-05-09 21:09:06
 ///

#include "Thread.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Test{
public:
	void doTask(){
		::srand(::time(NULL));
		while(true){
			int number = ::rand() % 100;
			cout << "number = " << number << endl;
			::sleep(1);
		}
	}

};//end of class MyThread


int main(){
	wd::Thread pthread(std::bind(&Test::doTask, Test()));
	pthread.start();
	pthread.join();
	return 0;
}


