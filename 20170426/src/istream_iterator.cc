 ///
 /// @file    istream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 16:10:28
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;


int main(void)
{
	vector<int> vec;
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's cap = " << vec.capacity() << endl;

	istream_iterator<int> isi(cin);

	//std::copy(isi, istream_iterator<int>(), vec.begin());
	std::copy(isi, istream_iterator<int>(), std::back_inserter(vec));

	//用的会更多一些
	ostream_iterator<int> osi(cout, ",");

	std::copy(vec.begin(), vec.end(), osi);

	return 0;
}
