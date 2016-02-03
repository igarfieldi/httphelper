/*
 * TimeoutException.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_SOCKET_EXCEPTIONS_TIMEOUTEXCEPTION_H_
#define HTTPHELPER_SOCKET_EXCEPTIONS_TIMEOUTEXCEPTION_H_

#include "socket/exceptions/CommException.h"
#include <string>

namespace httphelper {

class TimeoutException: public CommException {
public:
	TimeoutException(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_SOCKET_EXCEPTIONS_TIMEOUTEXCEPTION_H_ */
