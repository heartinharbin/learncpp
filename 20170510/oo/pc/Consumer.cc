 ///
 /// @file    Consumer.cc
 /// @author  heartinharbin
 /// @date    2017-05-11 11:21:24
 ///

#include "Consumer.h"
#include "Buffer.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd{
Consumer::Consumer(Buffer & buff)
:_buff(buff){}

void Consumer::run(){
	::srand(::time(NULL));
	while(true){
		int num = _buff.pop();
		cout << "Thread " << pthread_self() << "Consumer a number: " << num << endl;
		sleep(1);
	}
}

}//end of namespace wd
