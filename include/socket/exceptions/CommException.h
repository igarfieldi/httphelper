/*
 * SocketException.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_SOCKET_EXCEPTIONS_COMMEXCEPTION_H_
#define HTTPHELPER_SOCKET_EXCEPTIONS_COMMEXCEPTION_H_

#include <string>
#include <stdexcept>

namespace httphelper {

class CommException: public std::runtime_error {
public:
	CommException(const std::string& msg);
};

} /* namespace httphelper */

#endif /* HTTPHELPER_SOCKET_EXCEPTIONS_COMMEXCEPTION_H_ */
