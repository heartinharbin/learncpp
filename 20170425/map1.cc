///
/// @file    map1.cc
/// @author  heartinharbin
/// @date    2017-04-26 23:32:14
///

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

int test1(void){
	pair<int, string> t(731928, "ICBC");
	cout << t.first << "--->" << t.second << endl;

	map<int, string> mapIntStr{
		pair<int, string>(3, "北京"),
		pair<int, string>(2, "广州"),
		pair<int, string>(1, "深圳"),
		pair<int, string>(2, "上海")
	};
	map<int, string>::iterator it;
	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it){
		cout << it->first << "--->" << it->second << endl;
	}

	mapIntStr[4] = "天津";
	mapIntStr[3] = "太原";
	cout << "对map修改之后:" << endl;
	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it){
		cout << it->first << "--->" << it->second << endl;
	}
	return 0;
}

int main(){
	test1();
	return 0;
}


