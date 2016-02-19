/*
 * Socket.cc
 *
 *  Author: Florian Bethe
 */


#include "socket/PortSocket.h"
#include "socket/exceptions/CommException.h"
#include <netdb.h>
#include <unistd.h>
#include <cstring>


namespace httphelper {

const SocketHandle PortSocket::INVALID_HANDLE = -1;
const int PortSocket::MAX_CONNECTIONS = 1;

PortSocket::PortSocket(const std::string& address, unsigned int port) :
		address(address), port(port), handle(-1) {
}

PortSocket::~PortSocket() {
	close();
}

bool PortSocket::isValidSocket() const {
	// TODO: platform independency
	return (handle >= 0);
}

void PortSocket::open() {
	struct addrinfo hints;
	struct addrinfo* resolved;

	// First resolve the socket's name
	::memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if( ::getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &resolved) != 0 )
		throw CommException("Failed to get address info!");

	// Create the socket
	handle = ::socket(resolved->ai_family, resolved->ai_socktype, resolved->ai_protocol);
	if(!isValidSocket())
		throw CommException("Failed to create the socket!");

	// Enable address reuse
	int reuseAddress = 1;
	if( ::setsockopt(handle, SOL_SOCKET, SO_REUSEADDR, &reuseAddress, sizeof(int)) < 0 )
		throw CommException("Failed to specify the reuse of addresses for the socket!");

	// Bind the name (address/port combi) to the socket
	if( ::bind(handle, resolved->ai_addr, resolved->ai_addrlen) < 0 )
		throw CommException("Failed to bind the address to the socket!");

	// Mark the socket as passively listening for connections
	if( ::listen(handle, MAX_CONNECTIONS) < 0 )
		throw CommException("Failed to mark the socket as passively listening!");
}

void PortSocket::waitForConnection(Connection& connection) {
	if(connection.isOpen())
		connection.close();

	connection.open( ::accept(handle, NULL, NULL) );
}

bool PortSocket::waitForConnection(Connection& connection, long waitUSec) {
	if(connection.isOpen())
		connection.close();

	if(isConnectionWaiting(waitUSec)) {
		connection.open( ::accept(handle, NULL, NULL) );
	}

	return connection.isOpen();
}

bool PortSocket::isConnectionWaiting(long waitUSec) {
	fd_set descSet;
	FD_ZERO(&descSet);
	FD_SET(handle, &descSet);
	struct timeval timeout = {0, waitUSec};

	int status = ::select(handle + 1, &descSet, NULL, NULL, &timeout);

	if(status < 0)
		throw httphelper::CommException("Failed to wait for read descriptor!");

	return status > 0;
}

void PortSocket::close() {
	// TODO: wait for open connections?
	if(handle != INVALID_HANDLE) {
		if( ::shutdown(handle, SHUT_RDWR) ) {
			// TODO: wait for incoming packets?
		} else {
			if( ::close(handle) )
				throw CommException("Failed to close the socket!");
		}

		handle = INVALID_HANDLE;
	}
}

bool PortSocket::isOpen() const {
	return isValidSocket();
}

SocketHandle PortSocket::getHandle() const {
	return handle;
}

} /* namespace httphelper */
