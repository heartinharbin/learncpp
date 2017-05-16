 ///
 /// @file    Producer.cc
 /// @author  heartinharbin
 /// @date    2017-05-11 11:10:39
 ///

#include "Producer.h"
#include "Buffer.h"
#include <unistd.h>
#include <time.h>
//#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
namespace wd{
Producer::Producer(Buffer & buff)
: _buff(buff){
}

void Producer::run(){
	::srand(time(NULL));
	while(true){
		int number = ::rand() % 100;
		_buff.push(number);
		cout << "thread " << pthread_self() << "Produce a number: " << number << endl;
		sleep(1);
	}
}

}//end of namespace wd
