 ///
 /// @file    testThreadpool.cc
 /// @author  heartinharbin
 /// @date    2017-05-13 15:14:05
 ///

#include "Threadpool.h"
#include "Buffer.h"
#include "Task.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class MyTask
: public wd::Task{
public:
	void execute(){
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce a number: " << number << endl;
		sleep(1);
	}
};//end of class MyTask

int main(void){
	wd::Task * task = new MyTask;
	wd::Threadpool threadpool(10, 4);
	threadpool.start();

	size_t cnt = 20;
	while(cnt--){
		threadpool.addTask(task);
	}
	threadpool.stop();
	return 0;
}




