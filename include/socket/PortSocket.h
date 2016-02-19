/*
 * Socket.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_SOCKET_PORTSOCKET_H_
#define HTTPHELPER_SOCKET_PORTSOCKET_H_

#include "socket/Connection.h"
#include <string>

// TODO: compatibility with windows sockets
namespace httphelper {

typedef int SocketHandle;

class PortSocket {
protected:
	static const SocketHandle INVALID_HANDLE;
	static const int MAX_CONNECTIONS;

	std::string address;
	unsigned int port;
	SocketHandle handle;

	bool isValidSocket() const;

public:
	PortSocket(const std::string& address, unsigned int port);
	virtual ~PortSocket();

	void open();
	void waitForConnection(Connection& connection);
	bool waitForConnection(Connection& connection, long waitUSec);
	bool isConnectionWaiting(long waitUSec = 0);
	void close();

	bool isOpen() const;

	SocketHandle getHandle() const;
};

} /* namespace httphelper */

#endif /* HTTPHELPER_SOCKET_PORTSOCKET_H_ */
