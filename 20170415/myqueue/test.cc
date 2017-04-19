 ///
 /// @file    test.cc
 /// @author  heartinharbin
 /// @date    2017-04-18 21:57:28
 ///
#include "MyQueue.h" 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	MyQueue mq;
	int elem;
	cout << "isEmpty:" << mq.isEmpty() << "isFull:" << mq.isFull() << endl;
	mq.enQueue(520);
	
	cout << "isEmpty:" << mq.isEmpty() << "isFull:" << mq.isFull() << endl;
	mq.deQueue(elem);
	cout << "elem:" << elem << endl;
	cout << "isEmpty:" << mq.isEmpty() << "isFull:" << mq.isFull() << endl;
		
	return 0;
}




