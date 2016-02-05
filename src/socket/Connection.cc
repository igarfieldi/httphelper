/*
 * Connection.cc
 *
 *  Author: Florian Bethe
 */

#include "socket/exceptions/CommException.h"
#include "socket/exceptions/TimeoutException.h"
#include "socket/Connection.h"
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include <chrono>
#include <iostream>

namespace httphelper {

const ConnectionHandle Connection::INVALID_HANDLE = -1;
const size_t Connection::BUFFER_SIZE = 1024;
const size_t Connection::DEFAULT_READ_TIMEOUT = 1000;
const size_t Connection::DEFAULT_WRITE_TIMEOUT = 5000;

Connection::Connection() :
		Connection(DEFAULT_READ_TIMEOUT, DEFAULT_WRITE_TIMEOUT) {
}

Connection::Connection(size_t readTimeout, size_t writeTimeout) :
		handle(INVALID_HANDLE), buffer(new char[BUFFER_SIZE]),
		readTimeout(readTimeout), writeTimeout(writeTimeout),
		leftoverRead() {
}

Connection::Connection(ConnectionHandle handle) :
		Connection(handle, DEFAULT_READ_TIMEOUT, DEFAULT_WRITE_TIMEOUT) {
}

Connection::Connection(ConnectionHandle handle, size_t readTimeout,
		size_t writeTimeout) :
			handle(INVALID_HANDLE), buffer(new char[BUFFER_SIZE]),
			readTimeout(readTimeout), writeTimeout(writeTimeout),
			leftoverRead() {
	open(handle);
}

Connection::~Connection() {
	delete[] buffer;
	close();
}

bool Connection::isValidHandle(ConnectionHandle handle) {
	// TODO: platform independency
	return (handle != INVALID_HANDLE);
}

std::string Connection::read(const std::string& delim, size_t minBytes, size_t maxBytes) {
	std::string message = leftoverRead;
	bool readFromLeftovers = !leftoverRead.empty();
	leftoverRead = "";

	memset(buffer, 0, BUFFER_SIZE);

	size_t oldMsgSize = 0;
	ssize_t msgSize = 0;

	std::chrono::high_resolution_clock::time_point timeBefore = std::chrono::high_resolution_clock::now();

	// TODO: check what happens if the request/message has the same size as
	// your buffer?
	do {
		// If this call took too long, throw TimeoutException
		if(static_cast<unsigned int>(
				std::chrono::duration_cast<std::chrono::milliseconds>(
					std::chrono::high_resolution_clock::now() - timeBefore).count()) > readTimeout) {
			throw TimeoutException("Reading timeout!");
		}

		// If a delimiter is given, search for it (of course, the message has to
		// be long enough)
		if(!delim.empty() && (message.size() >= delim.size())) {
			size_t pos = message.find(delim, oldMsgSize);
			if(pos != std::string::npos) {
				// Store the message part after the delimiter for the next
				// read call
				leftoverRead = message.substr(pos + delim.size(), std::string::npos);
				return message.substr(0, pos + delim.size());
			}

			oldMsgSize = message.size() - delim.size();
		}

		// If a maximum amount of bytes to be read is given, check if we're over it
		if((maxBytes != 0) && (message.size() >= maxBytes)) {
			leftoverRead = message.substr(maxBytes, std::string::npos);
			return message.substr(0, maxBytes);
		}

		msgSize = 0;
		if(readFromLeftovers) {
			readFromLeftovers = false;
			msgSize = message.length();
		}
		if(this->isReadable(1000)) {
			msgSize = recv(handle, buffer, BUFFER_SIZE, 0);

			if(msgSize == 0)
				throw CommException("Connection closed by client");
			if(msgSize < 0)
				throw CommException("Failed to receive message from client!");

			message += buffer;
		}
	} while(!delim.empty() || (message.length() < minBytes) || (msgSize == BUFFER_SIZE));

	return message;
}

void Connection::write(const std::string& msg) {
	// Try to send the string as long as no error occurs and bytes remain unsent.
	// This will most likely only loop more than once if 'send' gets interrupted
	// by a system call/interrupt/trap/call gate/w.e (OS specific things).
	// It may also occur if the message is larger than the buffer

	unsigned long sendBytes = 0;

	std::chrono::high_resolution_clock::time_point timeBefore = std::chrono::high_resolution_clock::now();

	while(sendBytes < msg.length()) {
		if(this->isWritable(1000)) {
			memset(buffer, 0, BUFFER_SIZE);
			unsigned long msgLength = std::min(BUFFER_SIZE, msg.length() - sendBytes);
			std::strncpy(buffer, &msg.c_str()[sendBytes], msgLength);

			// Send the remaining part of the string
			ssize_t msgSize = send(handle, buffer, msgLength, 0);
			if(msgSize < 0)
				throw CommException("Failed to send message to client!");

			sendBytes += static_cast<unsigned long>(msgSize);
		}

		// In case of timeout, throw exception
		if(static_cast<unsigned int>(
				std::chrono::duration_cast<std::chrono::milliseconds>(
					std::chrono::high_resolution_clock::now() - timeBefore).count()) > readTimeout)
			throw TimeoutException("Writing timeout!");
	}
}

bool Connection::isReadable(long waitUSec) {
	if(!leftoverRead.empty())
		return true;

	fd_set descSet;
	FD_ZERO(&descSet);
	FD_SET(handle, &descSet);

	// See if the connection is ready to be read from
	struct timeval timeout = {0, waitUSec};
	int status = select(handle + 1, &descSet, NULL, NULL, &timeout);

	if(status < 0)
		throw CommException("Failed to check read descriptor!");

	return status > 0;
}

bool Connection::isWritable(long waitUSec) {
	fd_set descSet;
	FD_ZERO(&descSet);
	FD_SET(handle, &descSet);

	// See if the connection is ready to be written to
	struct timeval timeout = {0, waitUSec};
	int status = select(handle + 1, NULL, &descSet, NULL, &timeout);

	if(status < 0)
		throw CommException("Failed to check write descriptor!");

	return status > 0;
}

bool Connection::isOpen() {
	// TODO: try to write?
	return isValidHandle(handle);
}

void Connection::open(ConnectionHandle handle) {
	// Connection sockets cannot exist without valid handle
	if(!isValidHandle(handle))
		throw CommException("Tried to create connection without valid handle!");

	this->handle = handle;
}

void Connection::close() {
	// TODO: platform independency
	// TODO: wait for open connections?
	if(isValidHandle(handle)) {
		if(shutdown(handle, SHUT_RDWR)) {
			// TODO: wait for incoming packets?
		} else {
			if( ::close(handle) )
				throw CommException("Failed to close connection!");
		}
		handle = INVALID_HANDLE;
	}
}

} /* namespace httphelper */

