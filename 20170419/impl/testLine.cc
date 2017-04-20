 ///
 /// @file    testLine.cc
 /// @author  heartinharbin
 /// @date    2017-04-19 20:39:56
 ///#include "line.h" 
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
	Line line(1, 2, 3, 4);
	line.printLine();
	cout << endl;

	return 0;
}
