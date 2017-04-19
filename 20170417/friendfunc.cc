 ///
 /// @file    friendfunc.cc
 /// @author  heartinharbin
 /// @date    2017-04-18 22:19:50
 ///
#include <cmath> 
#include <iostream>
using std::cout;
using std::endl;

class Point{
private:
	int _x, _y;
	friend float dis(Point &p1, Point &p2);
public:
	Point(int i = 0, int j = 0)
	:_x(i)
	,_y(j){
	}

	void disp(){
		cout << "(" << _x << "," << _y << ")" << endl;
	}
};// end of class Point

float dis(Point & p1, Point & p2){
	float d = sqrt((p1._x - p2._x)*(p1._x - p2._x) 
			+ (p1._y - p2._y) * (p1._y - p2._y));
	return d;
}

int main(){
	Point p1(1, 2), p2(4, 5);
	p1.disp();
	cout << "and " << endl;
	p2.disp();

	cout << "disp=" << dis(p1, p2) << endl; 

	return 0;
}



