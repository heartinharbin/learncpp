#include <iostream>
using std::cout;
using std::endl;


class Point
{
	public:
		Point(int ix = 0, int iy = 0)
			: _ix(ix)
			  , _iy(iy)
	{}

		Point(const Point & rhs)
			: _ix(rhs._ix)
			  , _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

		Point & operator=(const Point & rhs)
		{
			cout << "Point & operator=(const Point &)" << endl;
			if(this != & rhs)
			{
				_ix = rhs._ix;
				_iy = rhs._iy;
			}
			return *this;
		}


		int getX() const
		{	return _ix;	}

		int getY() const
		{	return _iy;	}

		void display() const
		{
			cout << "(" << _ix
				<< "," << _iy
				<< ")" << endl;
		}

	private:
		int _ix;
		int _iy;
};


class Point3D 
: public Point
{
	public:
		Point3D(int ix, int iy, int iz)
			: Point(ix, iy)
			  , _iz(iz)
	{}

		void print() const
		{
			cout << "(" << getX()
				<< "," << getY() 
				<< "," << _iz
				<< ")" << endl;
		}

	private:
		int _iz;
};

int main(void)
{
	Point pt1(1, 2);
	pt1.display();

	Point3D pt2(3, 4 ,5);
	pt2.print();

	//	从类型适应的角度来讲，只有派生类能适应基类
	//做赋值之后

	pt1 = pt2;//调用Point的复制构造函数
	pt1.display();

	//pt2 = pt1;//Error
	//pt2.display();

	cout << "通过引用的方式:" << endl;
	Point & ref1 = pt2;
	ref1.display();

	//基类的指针去指向一个派生类对象
	Point * p1 = &pt2;
	p1->display();
	p1->print();
#if 0
	//Point3D * p2 = &pt1;//Error
	//p2->print();//
#endif
	return 0;
}

