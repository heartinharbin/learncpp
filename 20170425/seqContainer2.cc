 ///
 /// @file    seqContainer2.cc
 /// @author  heartinharbin
 /// @date    2017-04-26 20:53:37
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

void test1(){
	vector<int> vecInt = {1, 2, 3, 4, 5, 6, 7, 8};
	
	cout << "size:" << vecInt.size() << endl;
	cout << "cap:" << vecInt.capacity() << endl;
	
	vecInt.clear();
	
	cout << "size:" << vecInt.size() << endl;
	cout << "cap:" << vecInt.capacity() << endl;
}

int main(void){
	test1();
	return 0;
}










