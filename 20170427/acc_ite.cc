 ///
 /// @file    acc_ite.cc
 /// @author  heartinharbin
 /// @date    2017-04-27 19:06:55
 ///
#include <stdio.h> 
#include <iostream>
#include <istream>
#include <iterator>
#include <numeric>
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;


int main(void){
	istream_iterator<int> in(cin), eof;
	cout << accumulate(in, eof, 0) << endl;
	return 0;
}
