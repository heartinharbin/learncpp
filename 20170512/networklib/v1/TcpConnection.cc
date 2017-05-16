 ///
 /// @file    TcpConnection.cc
 /// @author  heartinharbin
 /// @date    2017-05-14 17:06:32
 ///

#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>

namespace wd{

TcpConnection::TcpConnection(int sockfd)
: _sockfd(sockfd)
, _sockIO(sockfd)
, _localAddr(wd::Socket::getLocalAddr(sockfd))
, _peerAddr(wd::Socket::getPeerAddr(sockfd))
, _isShutdownWrite(false){
	_sockfd.nonblock();
}

TcpConnection::~TcpConnection(){
	if(!_isShutdownWrite){
		_isShutdownWrite = true;
		shutdown();
	}
	printf("~TcpConnection()\n");
}

std::string TcpConnection::receive(){
	char buf[65536];
	memset(buf, 0, sizeof(buf));
	size_t ret = _sockIO.readline(buf, sizeof(buf));
	if(ret == 0){
		return std::string();
	}else{
		return std::string(buf);
	}
}

void TcpConnection::send(const std::string & msg){
	_sockIO.writen(msg.c_str(), msg.size());
}

void TcpConnection::shutdown(){
	if(!_isShutdownWrite)
		_sockfd.shutdownWrite();
	_isShutdownWrite = true;
}

std::string TcpConnection::toString(){
	char str[100];
	snprintf(str, sizeof(str), "%s:%d -> %s:%d",
			_localAddr.ip().c_str(),
			_localAddr.port(),
			_peerAddr.ip().c_str(),
			_peerAddr.port());
	return std::string(str);
}

}//end of namespace wd
