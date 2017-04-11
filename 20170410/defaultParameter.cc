 ///
 /// @file    defaultParameter.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:56:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int a = 1, int b = 3){
	return a + b;
}

int add(int a, int b, int c){
	return a + b + c;
}

int main(){
	int a = 3, b = 4;
//	cout << add(a) << endl;
//	cout << add() << endl;
	cout << add(a, b) << endl;
	return 0;
}
