 ///
 /// @file    TcpConnection.h
 /// @author  heartinharbin
 /// @date    2017-05-14 16:59:40
 ///

#ifndef __WD_TCPCONNECTION_H__
#define __WD_TCPCONNECTION_H__

#include "Noncopyable.h"
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"

#include <string>
#include <memory>
#include <functional>

namespace wd{

class TcpConnection : Noncopyable{
public:
	TcpConnection(int sockfd);
	~TcpConnection();

	std::string receive();
	void send(const std::string &msg);
	void shutdown();

	std::string toString();
private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;
};//end of class Noncopyable


}//end of namespace wd





#endif
