 ///
 /// @file    ofstream.cc
 /// @author  heartinharbin
 /// @date    2017-04-13 23:06:03
 ///
#include <iomanip>
#include <fstream> 
#include <iostream>
using std::cout;
using std::endl;
using std::ofstream;
using std::setw;
using std::setiosflags;
using std::ios;

int main(){
	ofstream ofs("result.txt", std::ios::app);
	if(!ofs.good()){
		cout << "ofstream open error!" << endl;
		return -1;
	}
//	ofs << setiosflags(ios::left) << setw(20) << "nihao" << setw(20) << "yangwen" << endl;
	ofs << setw(20) << "nihao" << setw(20) << "yangwen" << endl;
	ofs.close();
}

