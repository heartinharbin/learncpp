///
/// @file    multiset1.cc
/// @author  heartinharbin
/// @date    2017-04-26 23:42:31
///

#include <iostream>
using std::cout;
using std::endl;


#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;
using std::multiset;


int test0(void)
{
	//set内不能存放重复的元素, 默认情况下以从小到大的顺序进行排序
	multiset<int> setInt{2, 1, 3, 5, 4, 5, 3, 5, 6};	
	multiset<int>::iterator it = setInt.begin();
	for(; it != setInt.end(); ++it)
	{
		cout << *it << " ";
	}

	//set不支持下标访问运算符
	//cout << setInt[0] << endl;

	cout << endl;

	return 0;
}

int test1(void)
{
	//set内不能存放重复的元素, 默认情况下以从小到大的顺序进行排序
	multiset<int, std::greater<int> > setInt{2, 1, 3, 5, 4, 5, 3, 5, 6};	
	multiset<int>::iterator it = setInt.begin();
	for(; it != setInt.end(); ++it)
	{
		cout << *it << " ";
	}

	//set不支持下标访问运算符
	//cout << setInt[0] << endl;

	cout << endl;

	return 0;
}

class Complex
{
	public:
		Complex(double dreal, double dimag)
		: _dreal(dreal)
		, _dimag(dimag)
		{}

		friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
		friend bool operator<(const Complex & lhs, const Complex & rhs);
		friend bool operator>(const Complex & lhs, const Complex & rhs);
	private:
		double _dreal;
		double _dimag;
};

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal << " + " << rhs._dimag << " i ";
	return os;
}

bool operator<(const Complex & lhs, const Complex & rhs)
{
	if(lhs._dreal < rhs._dreal)
		return true;
	else
		return false;
}
bool operator>(const Complex & lhs, const Complex & rhs)
{
	if(lhs._dreal > rhs._dreal)
		return true;
	else
		return false;
}

void test2()
{
	set<Complex> setComplex{Complex(3, 2), Complex(1, 4), Complex(5, 6), Complex(9, 1)};

	for(auto & elem : setComplex)
	{
		cout << elem << endl;
	}
}

void test3()
{
	//1. 可以指定排序方式
	//2. 对于自定义类类型，必须要重载相应的比较函数
	set<Complex, std::greater<Complex> > setComplex{Complex(3, 2), Complex(1, 4), Complex(5, 6), Complex(9, 1)};

	for(auto & elem : setComplex)
	{
		cout << elem << endl;
	}
}

int main(void)
{
	test1();

	return 0;
}

