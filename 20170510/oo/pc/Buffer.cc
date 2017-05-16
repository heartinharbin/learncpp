 ///
 /// @file    Buffer.cc
 /// @author  heartinharbin
 /// @date    2017-05-11 10:26:53
 ///

#include "Buffer.h"

namespace wd{
Buffer::Buffer(size_t sz)
: _mutex()              //why
, _notFull(_mutex)
, _notEmpty(_mutex)
, _sz(sz){}

bool Buffer::full(){
	return _sz == _que.size();
}

bool Buffer::empty(){
	return _que.empty();
}

void Buffer::push(const Elemtype & elem){
	MutexLockGuard guard(_mutex);//zzzzzzz
	while(full())
		_notFull.wait();
	_que.push(elem);
	_notEmpty.notify();
}

Elemtype Buffer::pop(){
	MutexLockGuard guard(_mutex);
	while(empty()){
		_notEmpty.wait();
	}	
	Elemtype elem = _que.front();   //zzzzzzzz
	_que.pop();
	_notFull.notify();
	return elem;
}


}//end of namespace wd
