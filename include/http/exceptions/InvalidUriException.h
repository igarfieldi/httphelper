/*
 * InvalidUriException.h
 *
 *  Author: Florian Bethe
 */

#ifndef INCLUDE_HTTP_EXCEPTIONS_INVALIDURIEXCEPTION_H_
#define INCLUDE_HTTP_EXCEPTIONS_INVALIDURIEXCEPTION_H_

#include "http/exceptions/InvalidRequestException.h"

namespace httphelper {

class InvalidUriException :
		public InvalidRequestException {
public:
	InvalidUriException(const std::string& msg);
};

} /* namespace httphelper */
#endif /* INCLUDE_HTTP_EXCEPTIONS_INVALIDURIEXCEPTION_H_ */
