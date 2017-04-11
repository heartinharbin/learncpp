 ///
 /// @file    const2.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:51:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	int a = 100;
	int b = 200;
	const int *pa = &a;
	cout << "*pa = " << *pa << endl;
	
	pa = &b;
	cout << "*pa = " << *pa << endl;
	
//	*pa = 100;

	int * const pb = &a;
	*pb = 400;

	const int * const pc = &a;
	return 0;
}
