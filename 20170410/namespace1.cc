 ///
 /// @file    namespace1.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 21:06:32
 ///
 
#include <iostream>


namespace A{
	void displayA(){
		std::cout << "A::displayA()" << std::endl;
	}
}

//using namespace A;
using A::displayA;

namespace B{
	void displayB(){
	//	A::displayA();
		displayA();
	}
}

int main(){
	std::cout << "hello world" << std::endl;
	B::displayB();

	return 0;
}
