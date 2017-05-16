 ///
 /// @file    Noncopyable.h
 /// @author  heartinharbin
 /// @date    2017-05-14 19:50:15
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd{

class Noncopyable{
public:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};//end of class Noncopyable

}//end of namespace wd

#endif
