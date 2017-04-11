 ///
 /// @file    bool.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:41:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	bool b1 = 100;
	bool b2 = 1;
	bool b3 = true;
	bool b4 = false;
	bool b5 = -1;
	cout << b1 << endl
		 << b2 << endl
		 << b3 << endl
		 << b4 << endl
		 << b5 << endl;
	cout << "sizeof(bool) = " << sizeof(bool) << endl;
	return 0;
}

