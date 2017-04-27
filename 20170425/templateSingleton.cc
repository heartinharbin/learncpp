 ///
 /// @file    templateSingleton.cc
 /// @author  heartinharbin
 /// @date    2017-04-26 21:22:43
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point(int ix = 0, int iy = 0)
	:_ix(ix)
	,_iy(iy){
		cout << "Point()" << endl;
	}
	
	~Point(){
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};//end of class Point

template <typename T>
class Singleton{
	class AutoRelease{
	public:
		AutoRelease(){
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease(){
			if(_pInstance){
				cout << "~AutoRelease()" << endl;
				delete _pInstance;
			}
		}
	};//end of class AutoRelease

public:
	static T * getInstance(){
		if(NULL == _pInstance){
			_auto;
			_pInstance = new T;
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
	static T * _pInstance;
	static AutoRelease _auto;
};//end of class Singleton

template <typename T>
T * Singleton<T>::_pInstance = getInstance();


template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;


int main(void){
	Point * pt1 = Singleton<Point>::getInstance();
	Point * pt2 = Singleton<Point>::getInstance();

	printf("pt1 = %p\n", pt1);
	printf("pt2 = %p\n", pt2);
}




