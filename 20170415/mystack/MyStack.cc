 ///
 /// @file    MyStack.cc
 /// @author  heartinharbin
 /// @date    2017-04-17 22:49:51
 ///

#include "MyStack.h"
#include <iostream>
using std::cout;
using std::endl;

MyStack::MyStack()
:_top(-1){
}

bool MyStack::isEmpty(){
	return -1 ==  _top;
		
}

bool MyStack::isFull(){
	return STACKSIZE - 1 == _top;
}

bool MyStack::push(int elem){
	if(isFull()){
		return false;
	}
	_stack[++_top] = elem;
	return true;
}

bool MyStack::pop(int &elem){
	if(isEmpty()){
		return false;
	}
	elem = _stack[_top--];
	return true;
}

bool MyStack::top(int &elem){
	if(isEmpty()){
		return false;
	}
	elem = _stack[_top];
	return true;
}

