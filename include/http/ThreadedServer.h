/*
 * ThreadedServer.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_THREADEDSERVER_H_
#define HTTPHELPER_HTTP_THREADEDSERVER_H_

#include "socket/PortSocket.h"
#include "socket/Connection.h"
#include "http/StatusLine.h"
#include "threading/locks/CountingLock.h"
#include "threading/TaskQueue.h"
#include <thread>
#include <atomic>
#include <string>
#include <vector>

namespace httphelper {

class ThreadedServer {
protected:
	httphelper::PortSocket socket;
	std::atomic<bool> running;

	size_t maxConnections;
	threadutils::CountingLock connLock;

	threadutils::TaskQueue connQueue;
	std::vector<std::thread> connectionThreads;

	std::ofstream logfile;

public:
	ThreadedServer(unsigned int port, size_t maxConnections = 16);
	virtual ~ThreadedServer();

	void open();
	void close();

	void start();
	void stop();

	size_t getMaxConnections() const;

	void connectionWrapper(httphelper::Connection* conn);
	virtual void handleConnection(httphelper::Connection& conn) = 0;

	void logEntry(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_THREADEDSERVER_H_ */
