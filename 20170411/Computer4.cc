 ///
 /// @file    Computer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-11 11:42:38
 ///

 
#include <string.h> // C的头文件放在Ｃ++头文件的前面

#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float fPrice)
	: _brand(new char[strlen(brand) + 1])
	, _fPrice(fPrice)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
	}

	void print();

	//这是系统为我们提供的复制构造函数
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _fPrice(rhs._fPrice)
	{
		cout << "Computer(const Computer &)" << endl;
	}
#endif
	//复制构造函数的参数不能是对象，如果是，就会产生无穷递归
	//使用引用就可以打破无穷递归
	//const关键字不能去掉, 非const引用不能绑定到右值
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1])//深拷贝
	, _fPrice(rhs._fPrice)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer &)" << endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;
	}

private:
	char  * _brand;
	float _fPrice;
};

void Computer::print()
{
	cout << "品牌:" << _brand << endl
		 << "价格:" << _fPrice << endl;
}


int main(void)
{
	Computer com("Mac", 10000);
	com.print();
	//com.~Computer();//析构函数可以显式调用，但一般不这样用
	
	Computer com2 = com;
	com2.print();

	Computer & com3 = Computer("IBM", 7000);
	cout << "***********************" << endl;
//	com3.print();
#if 1
	int a = 10;
	int & ref = a;
	const int & ref1 = 10;//10叫右值, 不能进行取地址
#endif

	return 0;
}

