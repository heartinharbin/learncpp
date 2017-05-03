 ///
 /// @file    set.cc
 /// @author  heartinharbin
 /// @date    2017-04-28 22:04:58
 ///
 
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::set;
using std::back_insert_iterator;

int test1(void){
	int value = 100;
	set<int> setInt{1, 2, 3, 4, 5};

	auto it = setInt.find(4);
//	*it = 10;
	cout << value << endl;
	return 0;
}

template <typename Container>
void display( Container & c){
	//typename Container::iterator it;
	typename Container::const_iterator it;
	for(it = c.begin(); it != c.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

int test2(void){
	set<int> setInt{1, 2, 3, 4, 5};
	display(setInt);
	return 0;
}

int test3(void){
	vector<int> vec{1, 2, 3};
	list<int> listInt;

	copy(vec.begin(), vec.end(), back_insert_iterator<list<int> >(listInt));
	return 0;
}

int main(){
	test2();
	return 0;
}


