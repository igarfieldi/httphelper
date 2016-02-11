/*
 * ServerTemplate.cc
 *
 *  Author: Florian Bethe
 */

#include "http/ServerTemplate.h"
#include "string/timeutils.h"
#include "http/messages/Response.h"
#include "http/exceptions/httpexcepts.h"
#include "socket/exceptions/CommException.h"
#include "socket/exceptions/TimeoutException.h"

namespace httphelper {

ServerTemplate::ServerTemplate(unsigned int port) :
		socket("localhost", port), currConnection(), keepAlive(true),
		lastRequest(),
		validMethods(), uris(),
		requestTimeLimit(10),
		logfile("serverlog", std::fstream::out | std::fstream::app) {
	socket.open();
}

ServerTemplate::~ServerTemplate() {
}

void ServerTemplate::connect() {
	socket.waitForConnection(currConnection);
	logEntry("New connection established.");
}

void ServerTemplate::disconnect() {
	currConnection.close();
	logEntry("Current connection ended.");
}

bool ServerTemplate::getRequest(std::string& uri, std::string& msg) {
	uri = "";
	msg = "";

	try {
		if(!currConnection.isOpen())
			this->connect();

		while(!currConnection.isReadable(-1)) {}

		Request req(currConnection.read("\r\n\r\n"));
		this->lastRequest = req;

		if(!this->isUri(req.getUri())) {
			this->sendResponse(StatusLine::StatusCodes::CODE_400, "URI not found");
			return false;
		}

		if(!this->isValidMethod(req.getMethod())) {
			this->sendResponse(StatusLine::StatusCodes::CODE_501, "Method not supported");
			return false;
		}

		if(req.getField(Request::HOST).empty()) {
			this->sendResponse(StatusLine::StatusCodes::CODE_400, "Host-field missing");
			return false;
		}

		if(req.getField(Request::CONNECTION).empty() ||
				(req.getField(Request::CONNECTION).find("keep-alive")
					!= std::string::npos))
			keepAlive = true;
		else
			keepAlive = false;

		std::string contentLength = req.getField(Request::CONTENT_LENGTH);
		if(!contentLength.empty()) {
			unsigned long readBytes = std::stoul(contentLength);
			msg = currConnection.read("", readBytes, readBytes);
		}

		uri = req.getUri();
		return true;

	} catch(const std::invalid_argument& e) {
		this->sendResponse(StatusLine::StatusCodes::CODE_400, "Bad content length");
	} catch(const std::out_of_range& e) {
		this->sendResponse(StatusLine::StatusCodes::CODE_400, "Bad content length");
	} catch(const UnknownHttpVersionException& e) {
		this->sendResponse(StatusLine::StatusCodes::CODE_505, "Unknown HTTP version");
	} catch(const InvalidRequestException& e) {
		this->sendResponse(StatusLine::StatusCodes::CODE_400, "Malformed request");
	} catch(const TimeoutException& e) {
		this->sendResponse(StatusLine::StatusCodes::CODE_408, "Request timed out");
	} catch(const CommException& e) {
		logEntry("CommException; closing connection");
		currConnection.close();
	}

	return false;
}

bool ServerTemplate::sendResponse(const std::string& msg) {
	return this->sendResponse(StatusLine::StatusCodes::CODE_200, msg);
}

bool ServerTemplate::sendResponse(StatusLine::StatusCodes code, const std::string& msg) {
	Response resp(code);

	if(lastRequest.getMethod() != Request::HEAD)
		resp.setMessageBody(msg);

	if(currConnection.isOpen()) {
		try {
			currConnection.write(resp.toString());

			if(!keepAlive)
				currConnection.close();

			return true;
		} catch(const TimeoutException& e) {
		} catch(const CommException& e) {
			currConnection.close();
		}
	}

	return false;
}

const std::set<RequestMethod> ServerTemplate::getValidMethods() const {
	return validMethods;
}

void ServerTemplate::addValidMethod(const RequestMethod& method) {
	validMethods.insert(method);
}

void ServerTemplate::removeValidMethod(const RequestMethod& method) {
	validMethods.erase(method);
}

bool ServerTemplate::isValidMethod(const RequestMethod& method) const {
	return validMethods.find(method) != validMethods.end();
}

const std::set<std::string> ServerTemplate::getUris() const {
	return uris;
}

void ServerTemplate::addUri(const std::string& uri) {
	uris.insert(uri);
}

void ServerTemplate::removeUri(const std::string& uri) {
	uris.erase(uri);
}

bool ServerTemplate::isUri(const std::string& uri) const {
	return uris.find(uri) != uris.end();
}

unsigned int ServerTemplate::getRequestTimeLimit() const {
	return requestTimeLimit;
}

void ServerTemplate::setRequestTimeLimit(unsigned int limit) {
	this->requestTimeLimit = limit;
}

Request ServerTemplate::getLastRequest() const {
	return lastRequest;
}

bool ServerTemplate::isConnectionWaiting() {
	try {
		if(currConnection.isOpen())
			return currConnection.isReadable(0);

		return socket.isConnectionWaiting();
	} catch(const CommException& e) {
		logEntry("Error while checking for a waiting connection!");
		return false;
	}
}

void ServerTemplate::logEntry(const std::string& msg) {
	logfile << strutils::getCurrentTimeString() << ": " << msg << std::endl;
}

} /* namespace httphelper */
