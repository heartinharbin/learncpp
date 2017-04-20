 ///
 /// @file    singleton.cc
 /// @author  heartinharbin
 /// @date    2017-04-19 21:20:51
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
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;
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
	static AutoRelease _autoRlease;

};//end of class Singleton

Singleton * Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_autoRlease;

int main(){
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}





