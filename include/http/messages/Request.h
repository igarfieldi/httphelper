/*
 * Request.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_MESSAGES_REQUEST_H_
#define HTTPHELPER_HTTP_MESSAGES_REQUEST_H_

#include "http/messages/RequestMethod.h"
#include "http/headers/RequestHeader.h"
#include <map>
#include <string>

namespace httphelper {

class Request :
		public RequestHeader {
protected:
	RequestMethod method;
	std::string uri;
	std::string msgBody;

public:
	static const RequestMethod OPTIONS;
	static const RequestMethod GET;
	static const RequestMethod HEAD;
	static const RequestMethod POST;
	static const RequestMethod PUT;
	static const RequestMethod DELETE;
	static const RequestMethod TRACE;
	static const RequestMethod CONNECT;
	static const RequestMethod INVALID_METHOD;

	Request();
	Request(const std::string& msg);
	Request(const RequestMethod& method, const std::string& uri,
			const std::string& msgBody);
	virtual ~Request();

	const std::string& getMessageBody() const;
	Request& setMessageBody(const std::string& msgBody);

	RequestMethod getMethod() const;
	Request& setMethod(RequestMethod method);

	const std::string& getUri() const;
	Request& setUri(const std::string& uri);

	virtual std::string toString() const;
	virtual Request& parse(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_MESSAGES_REQUEST_H_ */
