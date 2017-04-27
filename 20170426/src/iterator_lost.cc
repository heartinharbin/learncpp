 ///
 /// @file    iterator_lost.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 17:26:39
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	vector<string> vec;
	
	vec.push_back("this is A");

	vector<string>::iterator it = vec.begin();
	bool flag = true;
	for(; it != vec.end(); ++it)
	{//注意：在遍历数据的过程中，不要添加或者删除数据，可以修改数据
		cout << "vec's size " << vec.size() << endl;
		cout << "vec's capa " << vec.capacity() << endl;
		cout << "*it = " << *it << endl;//访问过程中会发生段错误
		if(flag)
		{
			vec.push_back("this is B");//发生了动态扩容,导致底层数据结构的位置发生了变化
									   //迭代器it已经失效
			cout << "vec.push_back()" << endl;
			flag = false;
		}
	}
	return 0;
}
