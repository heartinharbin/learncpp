 ///
 /// @file    typecast.cc
 /// @author  heartinharbin
 /// @date    2017-04-19 22:05:57
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;

class AnotherPoint{
	friend class Point;
public:
	AnotherPoint(double dx, double dy)
	:_dx(dx)
	,_dy(dy){}

	friend std::ostream & operator<<(std::ostream & os, const AnotherPoint &rhs);
private:
	double _dx;
	double _dy;
};//end of class AnotherPoint


std::ostream & operator<<(std::ostream & os, const AnotherPoint &rhs){
	os << "(" << rhs._dx
	   << "," << rhs._dy
	   << ")";
	return os;
}

class Point{
public:
	Point(int ix = 0, int iy = 0)
	:_ix(ix)
	,_iy(iy){}

	Point(const AnotherPoint & rhs)
	:_ix(rhs._dx)
	,_iy(rhs._dy){
		cout << "Point(const AnotherPoint &)" << endl;
	}
/*
	operator AnotherPoint(){
		cout << "Point::operator AnotherPoint()" << endl;
		return AnotherPoint(_ix, _iy);
	}
*/	
	void print(){
		cout << "(" << _ix
			 << "," << _iy
			 << ")";
	}
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};//end of class Point

std::ostream & operator<<(std::ostream & os, const Point & rhs){
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

void test1(){
	Point pt1(1, 2);
//	cout << "pt1 = " << pt1 << endl;
}

void test2(){
	AnotherPoint pt2(3.3, 4.4);
	cout << "pt2 = " << pt2 << endl;
	
	Point pt1 = pt2;
	cout << "pt1 = " << pt1 << endl;
}

int main(void){
	test2();
}




