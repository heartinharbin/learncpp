 ///
 /// @file    const.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:44:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX 100
#define MAX2(x,y) ((x) > (y) ? (x) : (y))

int main(){
	const int a = 100;
	cout << "a = " << a << endl;
//	a = 10;
	int x = 1;
	const int b = x;
	cout << "b = " << b << endl;
	return 0;
}
