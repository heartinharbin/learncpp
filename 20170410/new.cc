 ///
 /// @file    new.cc
 /// @author  heartinharbin
 /// @date    2017-04-11 22:33:13
 ///
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

int global = 10;//全局静态区

int * test(void){
	int a = 10;
	int b = 20;
	int static c = 10;
	int * pa = (int*)malloc(sizeof(int));
	memset(pa, 0, sizeof(pa));
	*pa = 1;
	return pa;
}

int main(void){
	int * pa = test();
	cout << "*pa = " << *pa << endl;
	free(pa);

	int * pb = new int(2);
	cout << "*pa = " << *pa << endl;
	delete pb;

	int *pc = new int[10];
	delete [] pc;
	return 0;
}




