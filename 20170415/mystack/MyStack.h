 ///
 /// @file    MyStack.h
 /// @author  heartinharbin
 /// @date    2017-04-17 22:46:01
 ///
#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#define STACKSIZE 10

class MyStack{
public:
	MyStack();

	bool isEmpty();
	bool isFull();
	bool push(int elem);
	bool pop(int &elem);
	bool top(int &elem);

private:
	int _stack[STACKSIZE]; 
	int _top;

};//end of class MyStack


#endif
