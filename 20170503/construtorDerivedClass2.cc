 ///
 /// @file    construtorDerivedClass2.cc
 /// @author  heartinharbin
 /// @date    2017-05-04 20:19:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
#if 1
	Base(){
		cout << "Base()" << endl;
	}
#endif

	Base(int ix){
		cout << "ix = " << ix << endl;
	}
private:
};//end of class Base


class Derived : public Base{
public:
#if 0
	Derived(){
		cout << "Derived()" << endl;
	}
#endif
};//end of class Derived

int main(void){
	Derived d1;
	return 0;
}




