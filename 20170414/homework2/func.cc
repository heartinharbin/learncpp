#define _LOG4CPP_

#include "func.h"
#include "Mylog.h"

#include <iostream>
using std::cout;
using std::endl;

void func(){
	logError("hello allen, func() called");
}

int main(void){
	logError("error allen");
	logWarn("warn allen");

	func();

	return 0;
}




