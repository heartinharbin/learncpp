 ///
 /// @file    MyQueue.cc
 /// @author  heartinharbin
 /// @date    2017-04-17 23:07:06
 ///

#include "MyQueue.h"
#include <iostream>
using std::cout;
using std::endl;

MyQueue::MyQueue()
:_front(0)
,_rear(0){
}

bool MyQueue::isEmpty(){
	return _front == _rear;
}

//尾部插入  头部删除
bool MyQueue::isFull(){
	return (_rear + 1) % QUEUESIZE == _front;
}

bool MyQueue::enQueue(int elem){
	if(isFull()){
		return false;
	}
	_queue[_rear] = elem;
	_rear = (_rear + 1) % QUEUESIZE;
	return true;
}

bool MyQueue::deQueue(int &elem){
	if(isEmpty()){
		return false;
	}
	elem = _queue[_front];
	_front = (_front + 1) % QUEUESIZE;
	return true;
}

bool MyQueue::front(int & elem){
	if(isEmpty()){
		return false;
	}
	elem = _queue[_front];
	return true;
}


bool MyQueue::rear(int & elem){
	if(isEmpty()){
		return false;
	}
	elem = _queue[(_rear - 1 + QUEUESIZE) % QUEUESIZE];//注意
	return true;
}


