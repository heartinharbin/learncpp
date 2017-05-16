 ///
 /// @file    Consumer.h
 /// @author  heartinharbin
 /// @date    2017-05-11 11:17:27
 ///
#ifndef __WD_CONSUMER_H__
#define __WD_CONSUMER_H__

#include "Thread.h"

namespace wd{

class Buffer;
class Consumer
: public Thread{
public:	
	Consumer(Buffer &);
	virtual void run();
private:
	Buffer & _buff;
};//end of class Consumer

}//end of namespace wd


#endif

