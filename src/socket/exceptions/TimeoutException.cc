/*
 * TimeoutException.cc
 *
 *  Author: Florian Bethe
 */

#include "socket/exceptions/TimeoutException.h"

namespace httphelper {

TimeoutException::TimeoutException(const std::string& msg) :
	CommException("Timeout exception: " + msg) {
}

} /* namespace httphelper */
