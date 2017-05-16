 ///
 /// @file    TcpConnection.h
 /// @author  heartinharbin
 /// @date    2017-05-14 22:47:45
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

class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection : Noncopyable,
	public std::enable_shared_from_this<TcpConnection>{
public:
	typedef std::function<void(const TcpConnectionPtr &)> TcpConnectionCallback;
	TcpConnection(int sockfd);
	~TcpConnection();

	std::string receive();
	void send(const std::string & msg);
	void shutdown();

	std::string toString();

	void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();

private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;

};//end of class TcpConnection

}//end of namespace wd

#endif
