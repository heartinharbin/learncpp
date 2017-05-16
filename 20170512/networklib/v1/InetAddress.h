 ///
 /// @file    InetAddress.h
 /// @author  heartinharbin
 /// @date    2017-05-13 15:57:10
 ///

#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__

#include <netinet/in.h>
#include <string>

namespace wd{

class InetAddress{

public:
	InetAddress(short port);

	InetAddress(const char * ip, short port);

	InetAddress(const struct sockaddr_in & addr);

	const struct sockaddr_in * getSockAddrPtr() const;

	std::string ip() const;

	unsigned short port() const;

private:
	struct sockaddr_in _addr;
};//end of class InetAddress


}//end of namespace

#endif
