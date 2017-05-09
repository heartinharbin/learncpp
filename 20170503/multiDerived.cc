 ///
 /// @file    multiDerived.cc
 /// @author  heartinharbin
 /// @date    2017-05-04 20:54:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	void print(){
		cout << "A::print()" << endl;
	}
};//end of class A

class B{
public:
	void print(){
		cout << "B::print()" << endl;
	}
};//end of class B

class C : public A, public B{
public:
	void show(){
		A::print();
		B::print();
	}
};//end of class C

int main(void){
	C c;
	c.show();
	c.B::print();
	return 0;
}
