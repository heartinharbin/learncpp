 ///
 /// @file    templateSingleton.cc
 /// @author  heartinharbin
 /// @date    2017-04-21 22:30:21
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Singleton{
private:
	class AutoRelease;

public:
	static T * getInstance();/*{
		if(NULL == _pInstance){
			_pInstance = new T;
		}	
		return _pInstance;
	}
*/
private:
	Singleton();
	~Singleton();

private:
	static T * _pInstance;
	static AutoRelease _autoRelease;
};//end of class Singleton


template <typename T>
class Singleton<T>::AutoRelease{
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

class X{

};

class Point{

};



template <typename T>
T * Singleton<T>::getInstance(){
	if(NULL == _pInstance){
		_pInstance = new T;
	}
	return _pInstance;
}

template <typename T>
T * Singleton<T>::_pInstance = getInstance();

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;




int main(){
	X * p1 = Singleton<X>::getInstance();
	X * p2 = Singleton<X>::getInstance();
	printf("p1:%p\n", p1);
	printf("p2:%p\n", p2);


	Point * p3 = Singleton<Point>::getInstance();
	Point * p4 = Singleton<Point>::getInstance();
	printf("p3:%p\n", p3);
	printf("p4:%p\n", p4);

	return 0;
}



