 ///
 /// @file    virtualInherint.cc
 /// @author  heartinharbin
 /// @date    2017-05-05 17:14:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	A(int ia)
	:_ia(ia){
	}

	virtual void display(){
	
	};
private:
	int _ia;
};//end of class A


class B : virtual public A{
public:
	B(int ia, int ib)
	: A(ia)
	, _ib(ib){
	}
private:
	int _ib;
};

int main(void){
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	return 0;
}


