 ///
 /// @file    weak_ptr.cc
 /// @author  heartinharbin
 /// @date    2017-05-03 09:54:02
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class X{
public:
	X(){
		cout << "X()" << endl; 
	}

	~X(){
		cout << "~X()" << endl;
	}

	void display(){
		cout << "X::display()" << endl;
	}

};// end of class X

int main(void){
	weak_ptr<X> p1;
	{
		shared_ptr<X> p2(new X);
		cout << "p2's use_count() = " << p2.use_count() << endl;

		p1 = p2;
		cout << "p2's use_count() = " << p2.use_count() << endl;

		shared_ptr<X> p3 = p1.lock();
		if(p3){
			cout << "weak_ptr提升成功" << endl;
			p3->display();
		}else{
			cout << "weak_ptr提升失败，托管对象已经被销毁" << endl;
		}
	}
	cout << endl;

	shared_ptr<X> p4 = p1.lock();
	if(p4){
		cout << "weak_ptr提升成功" << endl;
		p4->display();
	}else{
		cout << "weak_ptr提升失败，托管对象已经被销毁" << endl;
	}
}

