 ///
 /// @file    auto_ptr.cc
 /// @author  heartinharbin
 /// @date    2017-05-02 23:44:49
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;

int main(void){
	double * ap = new double(7.77);
	auto_ptr<double> apd(ap);
	cout << "*apd = " << *apd << endl;
	cout << "ap = " << *ap << endl;
	cout << "apd'get() = " << apd.get() << endl;

	int * p1 = new int(10);
	auto_ptr<int> api(p1);
	auto_ptr<int> api2(api);

	cout << "*api2 = " << *api2 << endl;
//	cout << "*api = " << *api << endl;
	cout << "---" << endl;

	return 0;
}
