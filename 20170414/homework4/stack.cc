 ///
 /// @file    stack.cc
 /// @author  heartinharbin
 /// @date    2017-04-15 09:09:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack{
public:
	Stack()
	:_pstack(new int[10]())
	,_top(0){
		cout << "Stack()" << endl;
	};
	~Stack(){
		delete [] _pstack;
		cout << "~Stack()" << endl;
	}
	
	void push(){
	}
	void pop(){
	}
	int top(){
		return 0;	
	}
	bool empty(){
		return true;
	}
	bool full(){
		return false;
	}

private:
	int *_pstack;
	int _top;
};//end of class Stack
