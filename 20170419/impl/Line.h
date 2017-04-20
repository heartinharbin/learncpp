 ///
 /// @file    Line.h
 /// @author  heartinharbin
 /// @date    2017-04-19 20:26:57
 ///
#ifndef __LINE_H__
#define __LINE_H__

#include <iostream>
using std::cout;
using std::endl;

class Line{
	class LineImpl;
public:
	Line(int x1, int y1, int x2, int y2);
	void printLine();
	~Line();

private:
	LineImpl * _pimpl;
};//end of class Line


#endif


