 ///
 /// @file    singleton_nest.cc
 /// @author  heartinharbin
 /// @date    2017-04-20 21:20:57
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
private:
	class AutoRelease{
	public:
		AutoRelease(){
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease(){
			if(_pInstance){
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

public:
	static Singleton * getInstance(){
		if(NULL == _pInstance){
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}

private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
}; // end of class Singleton

Singleton * Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_autoRelease;


int main(void){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}





