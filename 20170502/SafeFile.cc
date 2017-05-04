 ///
 /// @file    SafeFile.cc
 /// @author  heartinharbin
 /// @date    2017-05-02 22:39:33
 ///
#include <stdio.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class SafeFile{
public:
	SafeFile(const string & filename)
	:_fp(::fopen(filename.c_str(), "rw+")){
		if(!_fp){
			cout << "fopen file"  << filename << "error!" << endl;
		}
	}

	SafeFile(FILE *fp)
	:_fp(fp){
	}

	void write(const string & msg){
		fwrite(msg.c_str(), 1, msg.size(), _fp);
	}

	~SafeFile(){
		if(_fp){
			fclose(_fp);
			cout << "fclose(fp)" << endl;
		}
	}

private:
	SafeFile(const SafeFile & rhs);
	SafeFile & operator=(const SafeFile & rhs);

private:
	FILE * _fp;
};//end of class SafeFile


int main(void){
	SafeFile sf("test.dat");

	sf.write("hello, wangdao");

	return 0;
}






