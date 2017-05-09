 ///
 /// @file    construtorDerviedClass.cc
 /// @author  heartinharbin
 /// @date    2017-05-04 20:12:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
	Base(){
		cout << "Base()" << endl;
	}
};

class Derived : public Base{
public:
	Derived(){
		cout << "Derived()" << endl;
	}

	Derived(int ix){
		cout << "Derived(int)" << endl;
	}
};

int main(void){
	Derived d1;
	Derived d2(1);
	return 0;
}
