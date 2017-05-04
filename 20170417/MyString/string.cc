 ///
 /// @file    string.cc
 /// @author  heartinharbin
 /// @date    2017-04-18 23:35:32
 ///
#include "String.h"

String::String()
:_pstr(new char[1]()){
	cout << "String::String()" << endl;
//	_pstr[0] = '\0';
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr) + 1]){
	cout << "String::String(const char *)" << endl;
	strcpy(_pstr, pstr);
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr) + 1]){
	cout << "String::String(const String &)" << endl;
	strcpy(_pstr, rhs._pstr);
}

String::~String(){
	cout << "String::~String()" << endl;
	delete [] _pstr;
}


String & String::operator=(const String &rhs){
	if(&rhs != this){
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr) + 1];
		strcpy(_pstr, rhs._pstr);
	}
	cout << "String::operator=(const String &)" << endl;
	return *this;//单一出口
} 

String & String::operator=(const char *pstr){
	delete [] _pstr;
	_pstr = new char[strlen(pstr) + 1];
	strcpy(_pstr, pstr);
	cout << "String::operator=(const char *)" << endl;
	return *this;
}

String & String::operator+=(const String &rhs){
	char *tmp = new char[strlen(_pstr) + 1];
	strcpy(tmp, _pstr);
	delete [] _pstr;
	if(this != &rhs){
	//	cout << "strlen(tmp):"  << strlen(tmp)  << endl;
		_pstr = new char[strlen(tmp) + strlen(rhs._pstr) + 1];
		strcpy(_pstr, tmp);
		strcat(_pstr, rhs._pstr);
	}else{
		_pstr = new char[strlen(tmp) * 2 + 1];
		strcpy(_pstr, tmp);
		strcat(_pstr, tmp);
	}
	delete [] tmp;
	tmp = NULL;
	cout << "String::operator+=(const String &)" << endl;
	return *this;
}

String & String::operator+=(const char *pstr){
	String tmp = pstr;
	return *this += tmp;	
	/*
	char *tmp = new char[strlen(_pstr) + 1];
	strcpy(tmp, _pstr);
	delete [] _pstr;
	if(_pstr != pstr){
		_pstr = new char[strlen(tmp) + strlen(pstr) + 1];
		strcpy(_pstr, tmp);
		strcat(_pstr, pstr);
	}else{
		_pstr = new char[strlen(tmp) * 2 + 1];
		strcpy(_pstr, tmp);
		strcpy(_pstr, tmp);
	}
	delete [] tmp;
	tmp = NULL;
	cout << "String::operator+=(const char *)" << endl;
	return *this;
	*/
}

char &String::operator[](std::size_t index){
	cout << "String::operator[](std::size_t)" << endl;
	return _pstr[index];
}


const char &String::operator[](std::size_t index) const{
	cout << "String::operator[](std::size_t) const" << endl;
	return _pstr[index];
}

std::size_t String::size() const{
	cout << "String::size()" << endl;
	return strlen(_pstr);
}

const char* String::c_str() const{
	cout << "String::c_str()" << endl;
	return _pstr;
}

bool operator==(const String &rhs1, const String &rhs2){
	cout << "operator==" << endl;
	return 0 == strcmp(rhs1._pstr, rhs2._pstr);
}

bool operator!=(const String &rhs1, const String &rhs2){
	cout << "operator!=" << endl;
	return 0 != strcmp(rhs1._pstr, rhs2._pstr);
}

bool operator<(const String &rhs1, const String &rhs2){
	cout << "operator<" << endl;
	return strcmp(rhs1._pstr, rhs2._pstr) < 0;
}
bool operator>(const String &rhs1, const String &rhs2){
	cout << "operator>" << endl;
	return strcmp(rhs1._pstr, rhs2._pstr) > 0;
}
bool operator<=(const String &rhs1, const String &rhs2){
	cout << "operator<=" << endl;
	return strcmp(rhs1._pstr, rhs2._pstr) <= 0;
}

bool operator>=(const String &rhs1, const String &rhs2){
	cout << "operator>=" << endl;
	return strcmp(rhs1._pstr, rhs2._pstr) >= 0;
}

std::ostream &operator<<(std::ostream &os, const String &s){
	cout << "operator<<" << endl;
	os << s._pstr << endl;
	return os;
}

// dangerous
std::istream &operator>>(std::istream &is, String &s){
	cout << "operator>>" << endl;
	char buf[STRING_SIZE_MAX];
	is >> buf;
	s = buf;
	return is;

}

String operator+(const String &rhs1, const String &rhs2){
	cout << "operator+(const String &, const String &)" << endl;
	
	String tmp;
	tmp += rhs1;
	tmp += rhs2;
	/*
	String tmp(rhs1);
	tmp += rhs2;
	*/
	return tmp;
}

String operator+(const String &rhs, const char *pstr){
	cout << "operator+(const String &, const char *)" << endl;
	String tmp(rhs);
	//tmp += rhs;
	tmp += pstr;
	return tmp;
}

String operator+(const char *pstr, const String &rhs){
	cout << "operator+(const char *, const String &)" << endl;
	String tmp(pstr);
//	tmp += pstr;
	tmp += rhs;
	return tmp;
}

void String::print(){
	if(_pstr)
		cout << _pstr << endl;
}


void test1(){
	String s1;
	cout << "size:" << s1.size() << endl;
	cout << "s1 = " << s1 << endl;
	String s2("hello world");
	cout << "size:" << s2.size() << endl;
	cout << "s2 = " << s2 << endl;

	String s3(s2);
	cout << "size:" << s3.size() << endl;
	cout << "s3 = " << s3 << endl;

	cin >> s1;
	cout << "size:" << s1.size() << endl;
	cout << "s1= " << s1 << endl;
}

void test2(){
	String s1 = "ilovepanda";
	cout << s1[2] << endl;
	cout << s1.c_str() << endl;
	
	const String s2 = "0123456789";
	cout << s2[2] << endl;
	cout << s2.c_str() << endl;
	
}

void test3(){
	String s1 = "yangwen";
	String s2 = "yangwen";
	String s3 = "luqing";
	cout << "s1 == s2:" << (s1 == s2) << endl;
	cout << "s1 != s2:" << (s1 != s2) << endl;
	cout << "s1 <= s2:" << (s1 <= s2) << endl;
	cout << "s2 >= s3:" << (s2 >= s3) << endl;
	cout << "s1 <= s2:" << (s1 <= s2) << endl;
	cout << "s1 <= s2:" << (s1 <= s2) << endl;
}

void test4(){
	String s1 = "i";
	String s2 = "love";
	String s3 = "panda";
	/*
	cout << (s1 + s2 + s3) << endl;
	cout << (s3 + s3) << endl;
	cout << "before" + s3 << endl;
	cout << s3 + "after" << endl;
	*/
	String s4 = s1 + s2 + s3;
	cout << s4 << endl;
//	cout << "s1:----->" << s1 << s1.size() << endl;
//	cout << "s2:----->" << s2 << s2.size() << endl;
//	cout << "s3:----->" << s3 << s3.size() << endl;
	String s5 = s1 + s2 + s3;
	cout << s5 << endl;
	cout << s1 + s2 + s3 << endl;
}

void test5(){
	String s1 = "i";
	String s2 = "love";
	String s3 = "panda";
	
//	s1 += "world";
	cout << s1 + s2 << endl;
	cout << s1 + s2 << endl;
}

void test6(){
	String s1;
	String s2;
	String s3;
	cout << s1.size() << endl;
	s1 + s2 + s3;
	cout << s1.size() << endl;
}

void test7(){
	String s1 = "rotk";
	s1 += "holy";
	cout << s1 << endl;
}
int main(void){
	test4();
	return 0;
}

