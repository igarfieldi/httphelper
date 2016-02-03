/*
 * Connection.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_SOCKET_CONNECTION_H_
#define HTTPHELPER_SOCKET_CONNECTION_H_

#include <string>
#include <cstring>

namespace httphelper {

typedef int ConnectionHandle;

class Connection {
protected:
	static const ConnectionHandle INVALID_HANDLE;
	static const size_t BUFFER_SIZE;
	static const size_t DEFAULT_READ_TIMEOUT;
	static const size_t DEFAULT_WRITE_TIMEOUT;

	ConnectionHandle handle;
	char* buffer;
	size_t readTimeout;
	size_t writeTimeout;
	std::string leftoverRead;

	bool isValidHandle(ConnectionHandle handle);

public:
	Connection();
	Connection(size_t readTimeout, size_t writeTimeout);
	Connection(ConnectionHandle handle);
	Connection(ConnectionHandle handle, size_t readTimeout, size_t writeTimeout);
	virtual ~Connection();

	size_t getReadTimeout() const;
	size_t getWriteTimeout() const;
	void setReadTimeout(size_t readTimeout);
	void setWriteTimeout(size_t writeTimeout);

	std::string read(const std::string& delim = "", size_t maxBytes = 0);
	void write(const std::string& str);

	virtual bool isOpen();
	virtual void open(ConnectionHandle handle);
	virtual void close();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_SOCKET_CONNECTION_H_ */
