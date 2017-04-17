 ///
 /// @file    string.cc
 /// @author  heartinharbin
 /// @date    2017-04-12 09:49:31
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

namespace A{
class String{
public:
	String()
	:_pstr(new char[7])
	{
		strcpy(_pstr, "whoami");
		cout << "A::String() " << endl;
	}
	String(const char *pstr)
	:_pstr(new char[strlen(pstr)+1])
	{
		strcpy(_pstr, pstr);
		cout << "A::String(const char *pstr) " << endl;
	}
	String(const String &rhs)
	:_pstr(new char[strlen(rhs._pstr)+1])
	{
		strcpy(_pstr, rhs._pstr);
		cout << "A::String(const String &rhs) " << endl;

	}
	String & operator=(const String & rhs){
		cout << "String & operator=(const String &rhs)" << endl;
		if(this == &rhs)
			return *this;

		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1];
		strcpy(_pstr, rhs._pstr);
		return *this;
	}
	~String(){
		cout << "~String()" << endl;
		delete [] _pstr;
	}

	void print(){
		cout << "A::print() " << _pstr << endl;
	}

private:
	char * _pstr;
};//end of class String
}//end of namespace A

using A::String;
int main(void){
//	String str1;
//	str1.print();
	
	String str2 = "Hello,world";
	str2 = "nihao";
	/*
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();
	*/
	return 0;


}

