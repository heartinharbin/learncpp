 ///
 /// @file    stringfun.cc
 /// @author  heartinharbin
 /// @date    2017-04-20 20:35:53
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test1(){
	string s1 = "hello world";
	cout << s1.substr(0, 5) << endl;
	cout << s1.substr(6) << endl;
	cout << s1.substr(6, 11) << endl;
//	cout << s1.substr(12) << endl;
}

void test2(){
	string s1 = "hello world";
	cout << s1.insert(s1.size(), " little panda") << endl;
	cout << s1.append(" little panda") << endl;
}

void test3(){
	string s1 = "hello world";
	cout << s1.erase(6, 1) << endl;
	cout << s1.insert(6, "W") << endl;
	cout << s1.replace(7, 1, "O") << endl;
}

void test4(){
	string name("yangwen");
	auto pos1 = name.find("wen");
	cout << pos1 << endl;
	auto 
	cout << name.find("ha") << endl;
}
int main(void){
	test4();

	return 0;
}
