 ///
 /// @file    Task.h
 /// @author  heartinharbin
 /// @date    2017-05-13 00:07:34
 ///

#ifndef __WD_TASK_H__
#define __WD_TASK_H__

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

//namespace wd{

class Task{
public:
	void execute(){
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce a nubmer: " << number << endl;
		sleep(1);
	}
};//end of class Task

//}//end of namespace wd

#endif
