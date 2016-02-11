/*
 * ServerTemplate.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_SERVERTEMPLATE_H_
#define HTTPHELPER_HTTP_SERVERTEMPLATE_H_

#include "socket/PortSocket.h"
#include "socket/Connection.h"
#include "http/messages/Request.h"
#include "http/messages/RequestMethod.h"
#include "http/StatusLine.h"
#include <map>
#include <string>
#include <set>
#include <fstream>

namespace httphelper {

class ServerTemplate {
protected:
	httphelper::PortSocket socket;
	Connection currConnection;
	bool keepAlive;
	Request lastRequest;

	std::set<RequestMethod> validMethods;
	std::set<std::string> uris;

	unsigned int requestTimeLimit;
	std::ofstream logfile;


	void connect();
	void disconnect();

public:
	ServerTemplate(unsigned int port);
	virtual ~ServerTemplate();

	bool getRequest(std::string& uri, std::string& msg);
	bool sendResponse(StatusLine::StatusCodes code, const std::string& msg);
	bool sendResponse(const std::string& msg);

	const std::set<std::string> getUris() const;
	void addUri(const std::string& uri);
	void removeUri(const std::string& uri);
	bool isUri(const std::string& uri) const;

	const std::set<RequestMethod> getValidMethods() const;
	void addValidMethod(const RequestMethod& method);
	void removeValidMethod(const RequestMethod& method);
	bool isValidMethod(const RequestMethod& method) const;

	unsigned int getRequestTimeLimit() const;
	void setRequestTimeLimit(unsigned int limit);

	Request getLastRequest() const;

	bool isConnectionWaiting();
	void logEntry(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_SERVERTEMPLATE_H_ */
