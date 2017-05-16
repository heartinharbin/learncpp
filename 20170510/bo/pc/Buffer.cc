 ///
 /// @file    Buffer.cc
 /// @author  heartinharbin
 /// @date    2017-05-12 20:57:31
 ///
 
#include "Buffer.h"
namespace wd{

Buffer::Buffer(size_t sz)
: _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _sz(sz){}

bool Buffer::full(){
	return _sz = _que.size();
}

bool Buffer::empty(){
	return _que.empty();
}

void Buffer::push(const ElemType & elem){
	MutexLockGuard guard(_mutex);
	while(full()){
		_notFull.wait();
	}
	_que.push(elem);
	_notEmpty.notify();
}

ElemType Buffer::pop(){
	MutexLockGuard gurad(_mutex);
	while(empty()){
		_notEmpty.wait();
	}
	ElemType tmp = _que.front();
	_que.pop();
	_notFull.notify();
	return tmp;
}
}//end of namespace wd


