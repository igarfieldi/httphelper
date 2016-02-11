/*
 * ClientConnection.cc
 *
 *  Author: Florian Bethe
 */

#include "socket/exceptions/CommException.h"
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <socket/ClientConnection.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>

namespace httphelper {

ClientConnection::ClientConnection() :
		Connection() {
}

ClientConnection::ClientConnection(size_t readTimeout, size_t writeTimeout) :
		Connection(readTimeout, writeTimeout) {
}

ClientConnection::ClientConnection(const std::string& address, unsigned int port) :
		Connection() {
	open(address, port);
}

ClientConnection::~ClientConnection() {
}

void ClientConnection::open(const std::string& address, unsigned int port) {
	struct addrinfo hints;
	struct addrinfo* resolved;

	// First resolve the socket's name
	::memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if( ::getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &resolved) != 0 )
		throw CommException("Failed to get address info!");

	handle = ::socket(resolved->ai_family, resolved->ai_socktype, resolved->ai_protocol);

	if(!isValidHandle(handle))
		throw CommException("Failed to create socket!");

	if( ::connect(handle, resolved->ai_addr, resolved->ai_addrlen) < 0 )
		throw CommException("Failed to connect to server!");
}

} /* namespace httphelper */
