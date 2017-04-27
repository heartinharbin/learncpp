 ///
 /// @file    seqContainer.cc
 /// @author  heartinharbin
 /// @date    2017-04-26 20:26:38
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

//test vector
void test1(void){
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	vector<int> vecInt(arr, arr + 8);
	cout << "size:" <<vecInt.size() << endl;
	cout << "cap:" << vecInt.capacity() << endl;
	vecInt.push_back(9);
	cout << "after push_back" << endl;
	cout << "size:" <<vecInt.size() << endl;
	cout << "cap:" << vecInt.capacity() << endl;

	vecInt.shrink_to_fit();
	cout << "after shrink_to_fit" << endl;
	cout << "size:" <<vecInt.size() << endl;
	cout << "cap:" << vecInt.capacity() << endl;
	
	cout << "use auto:" << endl;
	for(auto v : vecInt){
		cout << v << " ";
	}
	cout << endl;

	cout << "use iterator:" << endl;
	vector<int>::iterator it = vecInt.begin();
	for(; it != vecInt.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

//test deque
void test2(void){
	cout << "双端队列:" << endl;
	deque<int> dq{1, 2, 3, 4, 5, 6};
	for(size_t idx = 0; idx != dq.size(); ++idx){
		cout << dq[idx] << " ";
	}
	cout << endl;

	dq.push_back(7);
	dq.push_front(0);
	cout << "after push_back push_front" << endl;
	for(size_t idx = 0; idx != dq.size(); ++idx){
		cout << dq[idx] << " ";
	}
	cout << endl;

	dq.pop_back();
	dq.pop_front();
	cout << "after pop_back pop_front" << endl;
	for(size_t idx = 0; idx != dq.size(); ++idx){
		cout << dq[idx] << " ";
	}
	cout << endl;

}

void test3(){
	list<int> listInt{1, 2, 3, 4, 5, 6};
	for(size_t idx = 0; idx != listInt.size(); ++idx){
	//	cout << listInt[idx] << " "; //error
	}
	cout << endl;
}

int main(void){
	test3();
	return 0;
}


