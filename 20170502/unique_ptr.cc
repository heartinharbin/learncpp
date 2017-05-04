 ///
 /// @file    unique_ptr.cc
 /// @author  heartinharbin
 /// @date    2017-05-02 23:51:03
 ///
#include <memory>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getValue(){
	unique_ptr<int> upi(new int(6));
	return upi;
}

int test0(void){
	unique_ptr<double> upd(new double(8.88));
	cout << "*upd = " << *upd << endl;
	cout << "upd'get() = " << upd.get() << endl;

	unique_ptr<int> upi(new int(8));
//	unique_ptr<int> upi2(upi);
//
	getValue();

	unique_ptr<int> upi3(new int(10));
//	upi3 = upi;
//
	unique_ptr<int> upi4 = getValue();
	cout << "*upi4 = " << *upi4 << endl;
	return 0;
}

void test1(void){
	unique_ptr<int> upi(new int(6));
	vector<unique_ptr<int> > vec;
	vec.push_back(std::move(upi));
}

int main(void){
	test1();
	return 0;
}


