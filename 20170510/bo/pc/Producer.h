 ///
 /// @file    Producer.h
 /// @author  heartinharbin
 /// @date    2017-05-12 21:35:08
 ///

#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__


#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

namespace wd{

class Producer{
public:
	void execute(wd::Buffer & buff){
		::srand(::time(NULL));
		while(true){
			int number = ::rand() % 100;
			buff.push(number);
			cout << "Thread: " << pthread_self() << " producer a number: " << number << endl;
			sleep(1);
		}
	}

};

}//end of namespace wd


#endif
