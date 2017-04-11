 ///
 /// @file    namespace2.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:31:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int num = 100;

void f1(){
	cout << "::f1()" << endl;
}

namespace A{
int num = 10;

void func(int num){
	cout << "函数中的num:" << num << endl;
	cout << "A::num = " << A::num << endl;
	cout << "最外面的num = " << ::num << endl;
}
}//end of namespace A

int main(){
	A::func(3);
	f1();

	return 0;
}



