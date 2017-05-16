 ///
 /// @file    Noncopyable.h
 /// @author  heartinharbin
 /// @date    2017-05-12 23:30:08
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__
namespace wd{

class Noncopyable{
public:
	Noncopyable(){};  //别忘记写{}
	~Noncopyable(){};
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable &);
};

}//end of namespace wd
#endif
