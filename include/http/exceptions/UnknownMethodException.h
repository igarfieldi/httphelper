/*
 * UnknownMethodException.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNMETHODEXCEPTION_H_
#define HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNMETHODEXCEPTION_H_

#include "http/exceptions/InvalidRequestException.h"

namespace httphelper {

class UnknownMethodException :
		public InvalidRequestException {
public:
	UnknownMethodException();
	virtual ~UnknownMethodException();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_EXCEPTIONS_UNKNOWNMETHODEXCEPTION_H_ */
