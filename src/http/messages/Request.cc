/*
 * Request.cc
 *
 *  Author: Florian Bethe
 */

#include "http/messages/Request.h"
#include "http/exceptions/InvalidRequestException.h"
#include "http/exceptions/UnknownHttpVersionException.h"
#include "http/exceptions/UnknownMethodException.h"
#include "string/stringutils.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

namespace httphelper {

const RequestMethod Request::OPTIONS("OPTIONS");
const RequestMethod Request::GET("GET");
const RequestMethod Request::HEAD("HEAD");
const RequestMethod Request::POST("POST");
const RequestMethod Request::PUT("PUT");
const RequestMethod Request::DELETE("DELETE");
const RequestMethod Request::TRACE("TRACE");
const RequestMethod Request::CONNECT("CONNECT");
const RequestMethod Request::INVALID_METHOD("INVALID_METHOD");

Request::Request() :
		method(INVALID_METHOD), uri(), msgBody() {
}

Request::Request(const std::string& msg) :
		method(INVALID_METHOD), uri(), msgBody() {
	parse(msg);
}

Request::Request(const RequestMethod& method, const std::string& uri,
		const std::string& msgBody) :
				method(method), uri(uri), msgBody(msgBody) {
}

Request::~Request() {
}

const std::string& Request::getMessageBody() const {
	return msgBody;
}

void Request::setMessageBody(const std::string& msgBody) {
	this->msgBody = msgBody;
}

RequestMethod Request::getMethod() const {
	return method;
}

void Request::setMethod(RequestMethod method) {
	this->method = method;
}

const std::string& Request::getUri() const {
	return uri;
}

void Request::setUri(const std::string& uri) {
	this->uri = uri;
}

std::string Request::toString() const {
	return "HTTP/1.1 " + method.getName() + " " + uri + "\r\n" +
			RequestHeader::toString() + "\r\n" +
			msgBody;
}

void Request::parse(const std::string& msg) {
	if(msg.empty())
		throw InvalidRequestException("Empty parse string!");

	// Tokenize the request
	std::vector<std::string> headerMsgSplit = strutils::stringSplit(msg, "\r\n\r\n", 1);
	if(headerMsgSplit.size() < 2)
		throw InvalidRequestException("Missing end-of-request!");
	std::vector<std::string> tokens = strutils::stringSplit(headerMsgSplit[0], "\r\n", 1);

	// Parse start line
	// TODO: create class/enum for valid methods
	// TODO: check URI for correctness?
	std::vector<std::string> startLineTokens = strutils::stringSplit(tokens[0], " ");
	if(startLineTokens.size() != 3)
		throw InvalidRequestException("Invalid start line!");

	// Correct protocol
	// TODO: support 1.0/1.1/2.0?
	if(startLineTokens[2] != "HTTP/1.1")
		throw UnknownHttpVersionException();

	if((Request::OPTIONS != startLineTokens[0]) &&
			(Request::GET != startLineTokens[0]) &&
			(Request::HEAD != startLineTokens[0]) &&
			(Request::POST != startLineTokens[0]) &&
			(Request::PUT != startLineTokens[0]) &&
			(Request::DELETE != startLineTokens[0]) &&
			(Request::TRACE != startLineTokens[0]) &&
			(Request::CONNECT != startLineTokens[0]))
		throw UnknownMethodException();

	method = startLineTokens[0];
	uri = startLineTokens[1];

	// Get the message body
	msgBody = headerMsgSplit[1];

	// Let the base class do the field parsing
	Header::parse(tokens[1]);
}

} /* namespace httphelper */
