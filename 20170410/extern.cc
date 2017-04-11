 ///
 /// @file    extern.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 22:03:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C"
{
#endif
int add(int a, int b){
	return a + b;
}
#ifdef __cplusplus
}//end of extern "C"
#endif

int add(int a, int b, int c){
	return a + b + c;
}

int add(double a, double b, double c){
	return a + b + c;
}

void func1(){
}

void func2(int idx){
	cout << idx << endl;
	return;
}


int main(){
	int x = 1, y = 2, z = 3;
	cout << "x + y = " << add(x,y) << endl;
	cout << "x + y + z = " << add(x,y,z) << endl;

	return 0;
}


