 ///
 /// @file    construtorDerivedClass4.cc
 /// @author  heartinharbin
 /// @date    2017-05-04 20:38:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
	Base(int ix)
	:_ix(ix){
		cout << "Base(int)" << endl;
	}

	void display() const{
		cout << "Base::_ix = " << _ix << endl;
	}
private:
	int _ix;
};//end of class Base


class Derived : public Base{
public:
	Derived()
	: Base(0){
		cout << "Derived()" << endl;
	}

	Derived(int ix)
	: Base(ix){
		cout << "Derived(int)" << endl;
	}
private:

};//end of class Derived

int main(void){
	Derived d1;
	d1.display();

	Derived d2(1);
	d2.display();

	return 0;
}

