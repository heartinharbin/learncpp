 ///
 /// @file    SocketIO.h
 /// @author  heartinharbin
 /// @date    2017-05-14 20:50:21
 ///


#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__

#include <iostream>
namespace wd{

class SocketIO{
public:
	SocketIO(int sockfd);

	size_t readn(char * buf, size_t count);
	size_t writen(const char * buf, size_t count);
	size_t readline(char *buf, size_t max_len);
	
private:
	size_t recv_peek(char *buf, size_t count);
private:
	int _sockfd;
};//end of class SocketIO

}//end of namespace wd

#endif
