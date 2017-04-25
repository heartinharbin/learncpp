 ///
 /// @file    cowstring.cc
 /// @author  heartinharbin
 /// @date    2017-04-20 17:03:17
 ///
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class String{
public:
	String();
	String(const char *);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

	const char * c_str() const{
		return _pstr;
	}

	size_t size() const{
		return strlen(_pstr);
	}
	
	char & operator[](size_t idx);

	size_t refcount() const{
		return _pstr[size() + 1];
	}

	friend std::ostream & operator<<(std::ostream & os, const String &rhs);
private:
	void initRefcount(){
		_pstr[size() + 1] = 1;	
	}
	
	void increaseRefcount(){
		++_pstr[size() + 1];
	}

	void decreaseRefcount(){
		--_pstr[size() + 1];
	}
private:
	char * _pstr;
};//end of class String

std::ostream & operator<<(std::ostream & os, const String &rhs){
	os << rhs._pstr;
	return os;
}

String::String()
:_pstr(new char[2]){
	_pstr[0] = '\0';
	initRefcount();
}

String::String(const char * pstr)
:_pstr(new char[strlen(pstr) + 2]){
	strcpy(_pstr, pstr);
	initRefcount();
}

String::String(const String &rhs)
:_pstr(rhs._pstr){
	increaseRefcount();
}

String::~String(){
	decreaseRefcount();
	if(0 == refcount()){
		delete [] _pstr;
	}
}

String & String::operator=(const String & rhs){
	if(this != &rhs){
		decreaseRefcount();
		if(0 == refcount()){
			delete [] _pstr;
		}
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

char & String::operator[](size_t idx){
	static char nullchar = '\0';
	if(idx < size()){	//	条件
		if(refcount() > 1){
			char *ptmp = new char[size() + 2];
			strcpy(ptmp, _pstr);

			decreaseRefcount();
			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}else{
		return nullchar;
	}	
}

void test1(){
	String s1;
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;

	String s2 = "hello";
	String s3(s2);
	String s4 = s3;

	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;
	
	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());
	printf("s4's c_str's address = %p\n", s4.c_str());
	cout << endl;

	s1 = s4;
	cout << "执行完赋值操作后:" << endl;

	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;

	printf("s1's c_str's address = %p\n", s1.c_str());

	cout << endl << "修改s4字符串之后:" << endl;

	s4[0] = 'X';//做写操作

	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s4's refcount() = " << s4.refcount() << endl;

	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());
	printf("s4's c_str's address = %p\n", s4.c_str());


	cout << endl << "读取字符串s3[0]之后:" << endl;
	cout << s3[0] << endl;//做读操作(按理来说，读操作不应该进行复制)
	cout << "s1 = " << s1 << endl;
	cout << "s1's refcount() = " << s1.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s2's refcount() = " << s2.refcount() << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3's refcount() = " << s3.refcount() << endl;
	printf("s1's c_str's address = %p\n", s1.c_str());
	printf("s2's c_str's address = %p\n", s2.c_str());
	printf("s3's c_str's address = %p\n", s3.c_str());
}


void test2(){
	string s(1024 * 1024 * 10, 'x');
//	cout << s[0] << endl;

	time_t begin = time(NULL);
	for(size_t idx = 0; idx != 1000; ++idx){
		string scopy = s;
	}
	time_t end = time(NULL);
	printf("time:%ld\n", end - begin);
	return;
}


int main(void){
	test2();
	return 0;
}




