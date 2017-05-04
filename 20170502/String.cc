 ///
 /// @file    String.cc
 /// @author  heartinharbin
 /// @date    2017-05-02 21:51:56
 ///
#include <string.h> 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String{
public:
	String()
	:_pstr(new char[1]){
		cout << "String()" << endl;
		_pstr[0] = '\0';	
	}

	String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 1]){
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	String(const String &rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1]){
		cout << "String(const String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	String & operator=(const String &rhs){
		if(this != &rhs){
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	String(String && rhs)
	:_pstr(rhs._pstr){
		cout << "String(String && rhs)" << endl;
		rhs._pstr = NULL;
	}

	String & operator=(String &&rhs){
		cout << "String & operator=(String &&rhs)" << endl;
		if(this != & rhs){
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}
		return *this;
	}

	~String(){
		cout << "~String()" << endl;
		delete [] _pstr;
	}

	friend std::ostream & operator<<(std::ostream & os, const String &rhs);

private:
	char * _pstr;
};//end of class String

std::ostream & operator<<(std::ostream & os, const String &rhs){
	os << rhs._pstr;
	return os;
}

#if 0
String && func(){
}

int & func2(){}

#endif


int test1(void){
//	String && ref = func();
	vector<String> vec;
	vec.push_back("wangdao");

	String("wangdao");
	
	int a = 10;
	int & ref = a;

	const int & ref3 = 10;

	const int & ref4 = a;

	return 0;
}

int test2(void){
	String s1("hello");
	cout << "s1 = " << s1 << endl;

	String s2 = std::move(s1);
	cout << "s2 = " << s2 << endl;

	cout << "s1 = " << s1 << endl;//为什么不打印换行
	return 0;
}

int main(void){
	test2();
}
