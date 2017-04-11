 ///
 /// @file    inline.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 22:30:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define Max(a, b) ((a) > (b) ? (a) : (b))

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int x = 3;
	int y = 4;
    cout <<	max(x, y) << endl;
	return 0;
}
