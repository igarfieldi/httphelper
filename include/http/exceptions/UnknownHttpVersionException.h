/*
 * UnknownHttpVersionException.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNHTTPVERSIONEXCEPTION_H_
#define HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNHTTPVERSIONEXCEPTION_H_

#include "http/exceptions/InvalidRequestException.h"

namespace httphelper {

class UnknownHttpVersionException: public InvalidRequestException {
public:
	UnknownHttpVersionException();
	virtual ~UnknownHttpVersionException();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNHTTPVERSIONEXCEPTION_H_ */
