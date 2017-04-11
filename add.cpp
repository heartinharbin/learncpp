 ///
 /// @file    add.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-10 10:23:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	std::cout << "输入2个数字：" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "和为：" << v1 << "and" << v2 << "is" << v1+v2 << std::endl;
	return 0;
}
