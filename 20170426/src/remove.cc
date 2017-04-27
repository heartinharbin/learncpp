 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 17:13:19
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::remove_if;
using std::remove;
using std::ostream_iterator;


int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	vecInt[3] = vecInt[5] = vecInt[9] = 99;

	ostream_iterator<int> osi(cout, " ");

	std::copy(vecInt.begin(), vecInt.end(), osi);
	cout << endl;
	
	//erase-remove惯用法
	auto it = remove(vecInt.begin(), vecInt.end(), 99);
	vecInt.erase(it, vecInt.end());
	
	std::copy(vecInt.begin(), vecInt.end(), osi);
	cout << endl;


}
