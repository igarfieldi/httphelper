/*
 * Response.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_MESSAGES_RESPONSE_H_
#define HTTPHELPER_HTTP_MESSAGES_RESPONSE_H_

#include "http/headers/ResponseHeader.h"
#include "http/StatusLine.h"
#include <string>

namespace httphelper {

class Response :
		public ResponseHeader {
protected:
	StatusLine status;
	std::string msgBody;

public:
	Response(const StatusLine& status);
	Response(StatusLine::StatusCodes code);
	virtual ~Response();

	StatusLine getStatusLine() const;
	void setStatusLine(const StatusLine& status);
	void setStatusLine(StatusLine::StatusCodes code);

	std::string getMessageBody() const;
	void setMessageBody(const std::string& msgBody);

	virtual std::string toString() const;
	virtual void parse(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_MESSAGES_RESPONSE_H_ */
