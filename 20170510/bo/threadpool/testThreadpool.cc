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


int main(void){
	wd::Threadpool threadpool(10, 4);
	threadpool.start();

	size_t cnt = 20;
	while(cnt--){
		threadpool.addTask(std::bind(&Task::execute, Task()));
	}
	threadpool.stop();
	return 0;
}




