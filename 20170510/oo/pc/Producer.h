 ///
 /// @file    Producer.h
 /// @author  heartinharbin
 /// @date    2017-05-11 11:06:34
 ///

#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Thread.h"
namespace wd{
class Buffer;

class Producer
: public Thread{
public:
	Producer(Buffer & buf);
	virtual void run();
private:
	Buffer & _buff;
};//end of class Producer
}//end of namespacve wd

#endif
