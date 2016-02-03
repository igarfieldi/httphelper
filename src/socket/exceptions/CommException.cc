/*
 * SocketException.cc
 *
 *  Author: Florian Bethe
 */

#include "socket/exceptions/CommException.h"

namespace httphelper {

CommException::CommException(const std::string& msg) :
		std::runtime_error(msg) {
}

} /* namespace httphelper */
