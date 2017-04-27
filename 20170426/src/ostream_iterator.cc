 ///
 /// @file    ostream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 16:02:56
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;


int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5};

	ostream_iterator<int> osi(cout, ",");
	std::copy(vecInt.begin(), vecInt.end(), osi);
	//cout << endl;
	
	return 0;
}

