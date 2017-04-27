 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 16:37:06
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;

struct Function
{
	void operator()(int number)
	{
		cout << number << " ";
	}
};

int main(void)
{
	vector<int> vec{1, 2, 3, 4, 5};
	for_each(vec.begin(), vec.end(), Function());

	return 0;
}





