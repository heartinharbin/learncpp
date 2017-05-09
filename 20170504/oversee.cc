 ///
 /// @file    oversee.cc
 /// @author  heartinharbin
 /// @date    2017-05-05 09:51:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
	int func(double x){
		cout << "Base::func(int)" << endl;
		return _ix;
	}

protected:
	int _ix;
};//end of class Base


class Derived : public Base{
public:
	int func(int x){
		cout << "Derived::func(int)" << endl;
		_ix = 9;
		Base::_ix = 20;
		cout << "_ix = " << _ix << endl;
		cout << "Base::_ix = " << Base::_ix << endl;
		return _ix;
	}

	int _ix;
};

int main(void){
	Derived d1;
	d1.func(3.3);
	d1.Base::func(3);
	return 0;
}
