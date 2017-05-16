 ///
 /// @file    EpollPoller.h
 /// @author  heartinharbin
 /// @date    2017-05-14 22:46:13
 ///

#ifndef __WD_EPOLLPOLLER_H__
#define __WD_EPOLLPOLLER_H__

#include "Noncopyable.h"
#include "TcpConnection.h"
#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>

namespace wd{

class Acceptor;
class EpollPoller : Noncopyable{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;
	typedef std::function<void()> Functor;

	EpollPoller(Acceptor & acceptor);
	~EpollPoller();

	void loop();
	void unloop();
	void doPendingFunctors();

	void setConnectionCallback(EpollCallback cb);
	void setMessageCallback(EpollCallback cb);
	void setCloseCallback(EpollCallback cb);

private:
	void waitEpollfd();
	void handleConnection();
	void handleMessage(int peerfd);

private:
	Acceptor & _acceptor;
	int _epollfd;
	int _listenfd;
	bool _isLooping;

	typedef std::vector<struct epoll_event> EventList;
	EventList _eventsList;

	typedef std::map<int, TcpConnectionPtr> ConnectionMap;
	ConnectionMap _connMap;
	
	EpollCallback _onConnectionCb;
	EpollCallback _onMessageCb;
	EpollCallback _onCloseCb;
};//end of class EpollPoller

}//end of namespace wd

#endif
