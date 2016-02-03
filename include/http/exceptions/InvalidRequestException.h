/*
 * InvalidRequestException.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_EXCEPTIONS_INVALIDREQUESTEXCEPTION_H_
#define HTTPHELPER_HTTP_EXCEPTIONS_INVALIDREQUESTEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace httphelper {

class InvalidRequestException :
		public std::runtime_error {
public:
	InvalidRequestException(const std::string& msg);
	virtual ~InvalidRequestException();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_EXCEPTIONS_INVALIDREQUESTEXCEPTION_H_ */
