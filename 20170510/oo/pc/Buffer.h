 ///
 /// @file    Buffer.h
 /// @author  heartinharbin
 /// @date    2017-05-11 10:21:17
 ///

#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using std::queue;

namespace wd{
typedef int Elemtype;
class Buffer{
public:
	Buffer(size_t sz);
	
	bool full();
	bool empty();
	void push(const Elemtype & elem);
	Elemtype pop();
private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _sz;
	queue<Elemtype> _que;
};//enf of class Buffer
}//end of namespace wd


#endif
