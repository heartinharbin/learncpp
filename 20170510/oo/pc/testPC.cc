 ///
 /// @file    testPC.cc
 /// @author  heartinharbin
 /// @date    2017-05-11 11:43:23
 ///

#include "Producer.h"
#include "Consumer.h"
#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;


int main(void){
	wd::Buffer buffer(10);
	wd::Thread * pProducer = new wd::Producer(buffer);
	wd::Thread * pConsumer = new wd::Consumer(buffer);

	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();
	return 0;
}
