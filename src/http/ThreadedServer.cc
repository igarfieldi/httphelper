/*
 * ThreadedServer.cc
 *
 *  Author: Florian Bethe
 */

#include "http/ThreadedServer.h"
#include "http/messages/Request.h"
#include "http/messages/Response.h"
#include "socket/exceptions/TimeoutException.h"
#include "socket/exceptions/CommException.h"
#include "string/timeutils.h"
#include <iostream>

namespace httphelper {

ThreadedServer::ThreadedServer(unsigned int port, size_t maxConnections) :
		socket("localhost", port), running(false),
		maxConnections(maxConnections), connLock(maxConnections),
		connQueue(maxConnections, 0),
		connectionThreads(maxConnections),
		logfile("serverlog", std::fstream::out | std::fstream::app) {
}

ThreadedServer::~ThreadedServer() {
	this->close();
	this->stop();
}

void ThreadedServer::open() {
	socket.open();
}

void ThreadedServer::close() {
	socket.close();
}

void ThreadedServer::start() {
	if(!socket.isOpen())
		this->open();

	std::function<void(Connection*)> wrapperFunc =
			std::bind(&ThreadedServer::connectionWrapper, this, std::placeholders::_1);

	running = true;

	Connection *conn = new Connection();
	while(running) {
		if(socket.waitForConnection(*conn, 200000)) {
			connQueue.queue(wrapperFunc, conn);
			conn = new Connection();
		}
	}
}

void ThreadedServer::stop() {
	running = false;
}

void ThreadedServer::connectionWrapper(httphelper::Connection* conn) {
	connLock.lock();

	this->handleConnection(*conn);
	delete conn;

	connLock.unlock();
}

size_t ThreadedServer::getMaxConnections() const {
	return maxConnections;
}

void ThreadedServer::logEntry(const std::string& msg) {
	// TODO: thread safety
	logfile << strutils::getCurrentTimeString() << ": " << msg << std::endl;
}

} /* namespace httphelper */
