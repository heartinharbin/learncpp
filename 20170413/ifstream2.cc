 ///
 /// @file    ifstream2.cc
 /// @author  heartinharbin
 /// @date    2017-04-14 00:13:15
 ///
#include <fstream> 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;

int test(){
	ifstream ifs("a.txt");
	if(!ifs.good()){
		cout << "ifstream open error!" << endl;
		return -1;
	}
	vector<string> vecStr;
	vecStr.reserve(100);
	string str;
	while(getline(ifs, str)){
		vecStr.push_back(str);
	}

	for(auto & elem : vecStr){
		cout << elem << endl;
	}

	ifs.close();
	return 0;
}

int test1(){
	ifstream ifs("iostream.cc");
	if(!ifs.good()){
		cout << "ifstream open error!" << endl;
		return -1;
	}
	return 0;
}

int main(void){
	test();
	return 0;
}

