 ///
 /// @file    Noncopyable.h
 /// @author  heartinharbin
 /// @date    2017-05-12 20:06:27
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd{

class Noncopyable{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable&);
};//end of class Noncopyable

}//end of namespace wd

#endif
