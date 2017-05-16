 ///
 /// @file    Consumer.h
 /// @author  heartinharbin
 /// @date    2017-05-12 22:35:45
 ///

#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Buffer.h"
#include <unistd.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

//namespace wd{


class Consumer{
public:
	void execute(wd::Buffer &buff){
		while(true){
			int number = buff.pop();
			cout << "Thread: "<< pthread_self() << " consumer a number: " << number << endl;
			sleep(1);
		}
	}

};//end of class Consumer 
//}//end of namespace wd

#endif
