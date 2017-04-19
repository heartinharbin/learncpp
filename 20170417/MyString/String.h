 ///
 /// @file    string.cc
 /// @author  heartinharbin
 /// @date    2017-04-18 23:23:31
 ///
#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int STRING_SIZE_MAX = 1024 * 1024;

class String{
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	String &operator=(const String &);
	String &operator=(const char *);
	
	String &operator+=(const String &);
	String &operator+=(const char *);
	
	void print();

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;



private:

};//end of class String

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

#endif
