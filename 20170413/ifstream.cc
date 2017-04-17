 ///
 /// @file    ifstream.cc
 /// @author  heartinharbin
 /// @date    2017-04-13 22:49:45
 ///
#include <fstream> 
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;

int main(){
	ifstream ifs("a.txt");
	if(!ifs.good()){
		cout << "ifstream open error!" << endl;
		return -1;
	}
	char c;
	while(ifs.get(c)){
		cout << c;
	}
	ifs.close();
	return 0;
}
