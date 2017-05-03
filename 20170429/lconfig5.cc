 ///
 /// @file    lconfig5.cc
 /// @author  heartinharbin
 /// @date    2017-04-29 15:15:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//一般化设计
template <class T, class O>
struct testClass
{
	testClass()
	{
		cout << "I, O" << endl;
	}
};

//特殊化设计
template <class T>
struct testClass<T* ,T*>
{
	testClass()
	{
		cout << "T*, T*" << endl;
	}
};

template <class T>
struct testClass<const T*, T*>
{
	testClass()
	{
		cout << "const T*, T*" << endl;
	}
};

int main(){
	testClass<int,  char> obj1;
	testClass<int*, int*> obj2;
	testClass<const int*, int*> obj3;
	return 0;
}





