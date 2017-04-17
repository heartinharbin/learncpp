 ///
 /// @file    singleton.cc
 /// @author  heartinharbin
 /// @date    2017-04-12 22:13:41
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static	Singleton * getInstance(){
		if(NULL == _pInstance){
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

	static void destroy(){
		if(_pInstance){
			delete _pInstance;
		}
	}
private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}
	static Singleton * _pInstance;
};//end of class Singleton

Singleton * Singleton::_pInstance = NULL;

int main(){
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	Singleton *s3 = Singleton::getInstance();
	printf("%p\n", s1);
	printf("%p\n", s1);
	printf("%p\n", s1);

	Singleton::destroy();
	return 0;
}


