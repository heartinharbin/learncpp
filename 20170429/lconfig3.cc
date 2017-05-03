 ///
 /// @file    lconfig3.cc
 /// @author  heartinharbin
 /// @date    2017-04-29 15:01:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class testClass{
public:
	static int _data;
};//end of class testClass

template <>
int testClass<int>::_data = 1;

template <>
int testClass<char>::_data = 2;

int main(){
	cout << testClass<int>::_data << endl;
	cout << testClass<char>::_data << endl;

	testClass<int> obji1, obji2;
	testClass<char> objc1, objc2;

	cout << obji1._data << endl;
	cout << obji2._data << endl;
	cout << objc1._data << endl;
	cout << objc2._data << endl;

	obji1._data = 3;
	objc2._data = 4;

	cout << obji1._data << endl;
	cout << obji2._data << endl;
	cout << objc1._data << endl;
	cout << objc2._data << endl;

	return 0;
}







