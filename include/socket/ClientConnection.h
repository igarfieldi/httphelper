/*
 * ClientConnection.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_SOCKET_CLIENTCONNECTION_H_
#define HTTPHELPER_SOCKET_CLIENTCONNECTION_H_

#include "socket/Connection.h"
#include <string>

namespace httphelper {

class ClientConnection :
			public Connection {
public:
	ClientConnection();
	ClientConnection(size_t readTimeout, size_t writeTimeout);
	ClientConnection(const std::string& address, unsigned int port);
	virtual ~ClientConnection();

	void open(const std::string& address, unsigned int port);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_SOCKET_CLIENTCONNECTION_H_ */
