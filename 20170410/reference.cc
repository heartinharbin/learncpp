 ///
 /// @file    reference.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 22:40:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	int a = 10;
	int & refa = a;
	refa = 20;

	cout << "refa = " << refa << endl
		 << "a = " << a << endl;

	int b = 30;
	int &refb = b;

	refa = b;

	cout << "refa = " << refa << endl
	<<"a = " << a << endl
	<<"b = " << b << endl;
	return 0;
}
