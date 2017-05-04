///
/// @file    circle_reference.cc
/// @author  heartinharbin
/// @date    2017-05-03 00:06:03
///

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Parent;

class Child
{
	public:
		Child(){	cout << "Child()" << endl;	}

		~Child(){	cout << "~Child()" << endl;}

		shared_ptr<Parent> _parentPtr;
};

class Parent
{
	public:
		Parent(){	cout << "Parent()" << endl;	}

		~Parent() {	cout << "~Parent()" << endl;	}

		shared_ptr<Child> _childPtr;
};


int main(void)
{
	shared_ptr<Child> child(new Child);
	shared_ptr<Parent> parent(new Parent);

	cout << "child's use_count() = " << child.use_count() << endl;
	cout << "parent's use_count() = " << parent.use_count() << endl;

	cout << endl;
	child->_parentPtr = parent;//引用计数加１
	parent->_childPtr = child;//引用计数不变

	cout << "child's use_count() = " << child.use_count() << endl;
	cout << "parent's use_count() = " << parent.use_count() << endl;


	return 0;
}


