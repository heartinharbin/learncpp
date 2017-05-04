///
/// @file    abuse_shared_ptr.cc
/// @author  heartinharbin
/// @date    2017-05-03 00:19:15
///
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


class Point
{
	public:
		Point(int ix, int iy)
			: _ix(ix)
			  , _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

		~Point(){	cout << "~Point()" << endl;	}

		Point * add(const Point * rhs)
		{
			_ix += rhs->_ix;
			_iy += rhs->_iy;

			return this;
		}

		friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	private:
		int _ix;
		int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}


//避免产生误用的宗旨：一个裸指针只交给一个智能指针进行托管，
//托管以后的所有操作都通过智能指针来进行
void test0()
{	//一个堆对象会被销毁两次
	Point * pt = new Point(1, 2);
	shared_ptr<Point> sp1(pt);
	shared_ptr<Point> sp2(pt);
}

void test1()
{
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	sp2.reset(sp1.get());//当执行该语句之后，对象(1,2)被sp1,sp2托管
	cout << *sp1 << endl;
	cout << *sp2 << endl;
}

void test2()
{
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp2->add(sp1.get()));//sp2所托管的指针又被sp3进行托管了
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	cout << *sp3 << endl;
}



int main(void)
{
//	test0();
	test1();
//	test2();

	return 0;
}

