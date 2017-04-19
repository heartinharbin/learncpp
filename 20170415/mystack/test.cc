 ///
 /// @file    test.cc
 /// @author  heartinharbin
 /// @date    2017-04-18 21:45:57
 ///
#include "MyStack.h" 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	MyStack ms;
	int elem;
	cout << "栈是否为空：" << ms.isEmpty() << "栈是否满：" << ms.isFull() << endl;
	ms.push(1);
	cout << "栈是否为空：" << ms.isEmpty() << "栈是否满：" << ms.isFull() << endl;
	ms.top(elem);
	cout << "top:" << elem << endl;
	ms.pop(elem);
	cout << "pop:" << elem << endl;
	cout << "栈是否为空：" << ms.isEmpty() << "栈是否满：" << ms.isFull() << endl;
	return 0;
}
