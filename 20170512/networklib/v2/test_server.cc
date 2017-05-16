 ///
 /// @file    test_server.cc
 /// @author  heartinharbin
 /// @date    2017-05-15 10:10:16
 ///

#include "SocketUtil.h"
#include "TcpConnection.h"
#include "Acceptor.h"
#include "EpollPoller.h"
#include <iostream>

using std::cout;
using std::endl;

void onConnection(const wd::TcpConnectionPtr &conn){
	cout << conn->toString() << endl;
	conn->send("hello, welcome to chat server.\r\n");
}

void onMessage(const wd::TcpConnectionPtr &conn){
	std::string s(conn->receive());
//	printf("receive: %s\n", s.c_str());
	conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn){
	printf("%s close\n", conn->toString().c_str());
}

int main(int argc, const char *argv[]){
	wd::InetAddress addr("192.168.74.129", 9999);
	wd::Acceptor acceptor(wd::createSocketFd(), addr);
	acceptor.ready();

	wd::EpollPoller poller(acceptor);
	poller.setConnectionCallback(&onConnection);
	poller.setMessageCallback(&onMessage);
	poller.setCloseCallback(&onClose);

	poller.loop();

	return 0;
}


