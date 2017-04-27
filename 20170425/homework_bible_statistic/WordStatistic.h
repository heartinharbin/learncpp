#ifndef __WORDSTATISTIC_H__
#define __WORDSTATISTIC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::setiosflags;
using std::ios;

#define IN 1
#define OUT 0
#define CENSUS_SIZE 26

typedef struct word{
	char str[20];
	int count;
	struct word *next;
}wd, *pwd;


#endif