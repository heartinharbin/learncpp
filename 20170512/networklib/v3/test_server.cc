///
/// @file    test_server.cc
/// @author  heartinharbin
/// @date    2017-05-16 00:29:22
///



#include "TcpServer.h"
#include <iostream>
using std::cout;
using std::endl;

void onConnection(const wd::TcpConnectionPtr &conn)
{
	cout << conn->toString() << endl;
	conn->send("hello, welcome to Chat Server.\r\n");
}

void onMessage(const wd::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());
	conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn)
{
	printf("%s close\n", conn->toString().c_str());
}

int main(int argc, const char *argv[])
{
	wd::TcpServer tcpserver("192.168.74.129", 9999);
	tcpserver.setConnectionCallback(&onConnection);
	tcpserver.setMessageCallback(&onMessage);
	tcpserver.setCloseCallback(&onClose);

	tcpserver.start();

	return 0;
}

