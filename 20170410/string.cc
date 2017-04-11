 ///
 /// @file    string.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 22:56:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test2(){
	string s1 = "iloveyk";
	cout << s1.size() << endl;

	s1.append(" wangdao");
	cout << s1 << endl;

	size_t pos = s1.find("wang");
	string sub = s1.substr(pos, 4);
	cout << "sub = " << sub << endl;

	string::iterator it = s1.begin();
	for(; it != s1.end(); ++it){
		cout << *it << "\n";
	}

	for(auto & elem : s1){
		cout << elem << "\n";
	}
}

int main(){
	test2();
	return 0;
}
