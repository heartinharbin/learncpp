 ///
 /// @file    testPC.cc
 /// @author  heartinharbin
 /// @date    2017-05-12 22:45:27
 ///

#include "Producer.h"
#include "Consumer.h"
#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;
using wd::Producer;
int main(void){
	wd::Buffer buffer(10);
	wd::Thread producer(std::bind(&Producer::execute, Producer(), std::ref(buffer)));
	wd::Thread consumer(std::bind(&Consumer::execute, Consumer(), std::ref(buffer)));

	producer.start();
	consumer.start();

	producer.join();
	consumer.join();
	return 0;
}
