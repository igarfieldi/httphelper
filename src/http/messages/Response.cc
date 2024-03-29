/*
 * Response.cc
 *
 *  Author: Florian Bethe
 */

#include "http/messages/Response.h"
#include <iostream>

namespace httphelper {

Response::Response(const StatusLine& status) :
		ResponseHeader(), status(status) {
}

Response::Response(StatusLine::StatusCodes code) :
		ResponseHeader(), status(code) {
}

Response::~Response() {
}

StatusLine Response::getStatusLine() const {
	return status;
}

Response& Response::setStatusLine(const StatusLine& status) {
	this->status = status;
	return *this;
}

Response& Response::setStatusLine(StatusLine::StatusCodes code) {
	this->status = StatusLine(code);
	return *this;
}

std::string Response::getMessageBody() const {
	return msgBody;
}
Response& Response::setMessageBody(const std::string& msgBody) {
	this->msgBody = msgBody;
	this->setField(Response::CONTENT_LENGTH, std::to_string(msgBody.length()));
	return *this;
}

std::string Response::toString() const {
	return status.toString() + "\r\n" +
			ResponseHeader::toString() + "\r\n" +
			msgBody;
}

Response& Response::parse(const std::string& msg) {
	std::cout << msg << std::endl;

	return *this;
	// TODO: actual implementation for correct parsing
	/*
	std::stringstream stream(msg);
	std::string token;

	stream >> token;
	std::transform(token.begin(), token.end(), token.begin(), ::tolower);
	if(token != "http/1.1")
		return false;

	stream >> token;

	while(!stream.eof()) {


	}*/
}

} /* namespace httphelper */
