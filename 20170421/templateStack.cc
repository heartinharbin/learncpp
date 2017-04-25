 ///
 /// @file    templateStack.cc
 /// @author  heartinharbin
 /// @date    2017-04-21 20:52:26
 ///
 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T, int _size = 10>
class Stack{
public:
	Stack();
	~Stack();
	void push(T num);
	void pop();
	bool full();
	bool empty();
	T top();
private:
	int _top;
	T * _arr;
};//end of class Stack

template <typename T, int _size>
Stack<T, _size>::Stack()
:_top(-1)
,_arr(new T[_size]){}


template <typename T, int _size>
Stack<T, _size>::~Stack(){
	delete [] _arr;
}

template <typename T, int _size>
bool Stack<T, _size>::empty(){
	return _top == -1;
}

template <typename T, int _size>
bool Stack<T, _size>::full(){
	return _top == _size - 1;
}


template <typename T, int _size>
void Stack<T, _size>::push(T elem){
	if(!full())
		_arr[++_top] = elem;
	else
		cout << "stack is full" << endl;
}

template <typename T, int _size>
void Stack<T, _size>::pop(){
	if(!empty())
		--_top;
	else
		cout << "stack is empty" << endl;
}

template <typename T, int _size>
T Stack<T, _size>::top(){
	return _arr[_top];
}

void test1(void){
	Stack<int> stack;
	cout << "初始时，栈是否为空？" << stack.empty() << endl;
	stack.push(1);
	cout << "此时，栈是否为空？" << stack.empty() << endl;
	for(int idx = 2; idx != 12; ++ idx){
		stack.push(idx);
	}
	cout << "此时，栈是否已满？" << stack.full() << endl;
	while(!stack.empty()){
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时，栈是否为空？" << stack.empty() << endl;
}

void test2(){
	vector<string> vecstr;
	Stack<string> stack;
	cout << "初始时，栈是否为空？" << stack.empty() << endl;
	string s1(2, 'A');
	stack.push(s1);
	cout << "此时，栈是否为空？" << stack.empty() << endl;
	for(int idx = 1; idx != 11; ++idx){
		string tmp(2, 'A' + idx);
		stack.push(tmp);
	}
	cout << "此时，栈是否已满？" << stack.full() << endl;
	while(!stack.empty()){
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时，栈是否为空？" << stack.empty() << endl;
}

int main(void){
	test2();
}



