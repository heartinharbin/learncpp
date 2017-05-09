 ///
 /// @file    multiDerived2.cc
 /// @author  heartinharbin
 /// @date    2017-05-04 20:58:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	A(int ix = 0) : _ix(ix){}

	void setX(int ix){
		_ix = ix;
	}

	void display(){
		cout << "A::_ix = " << _ix << endl;
	}
private:
	int _ix;
};//end of class A

class B : virtual public A
{};

class C : virtual public A
{};

class D : public B, public C{
public:
	D(int ix) : A(ix){}
};

int main(void){
	D d(3);
	d.B::display();
	d.C::display();
	d.A::display();
	return 0;
}
