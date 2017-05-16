 ///
 /// @file    Buffer.h
 /// @author  heartinharbin
 /// @date    2017-05-12 20:44:10
 ///


#ifndef __WD_BUFFER_H__
#define __WD_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

using std::queue;

namespace wd{

typedef int ElemType;

class Buffer{
public:
	Buffer(size_t sz);

	bool full();
	bool empty();
	void push(const ElemType & elem);
	ElemType pop();
private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _sz;
	queue<ElemType> _que;
};//end of class Buffer

}//end of namespace wd

#endif
