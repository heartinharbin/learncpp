 ///
 /// @file    replace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 17:01:24
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::replace_if;
using std::ostream_iterator;

bool f(int number)
{
	return number < 3;
}

int test0(void)
{
	cout << "test0()" << endl;
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	replace_if(vecInt.begin(), vecInt.end(), f, 7);

	ostream_iterator<int> osi(cout, " ");
	std::copy(vecInt.begin(), vecInt.end(), osi);

	return 0;
}

int test1(void)
{
	cout << "test1()" << endl;
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	std::less<int> lt;
	//replace_if(vecInt.begin(), vecInt.end(), std::bind2nd(lt, 3), 7);
	replace_if(vecInt.begin(), vecInt.end(), std::bind1st(lt, 3), 7);

	ostream_iterator<int> osi(cout, " ");
	std::copy(vecInt.begin(), vecInt.end(), osi);

	return 0;
}

int main(void)
{
	test1();

	return 0;
}
