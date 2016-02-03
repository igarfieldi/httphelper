/*
 * InvalidRequestException.cc
 *
 *  Author: Florian Bethe
 */

#include "http/exceptions/InvalidRequestException.h"

namespace httphelper {

InvalidRequestException::InvalidRequestException(const std::string& msg) :
	std::runtime_error(msg) {
}

InvalidRequestException::~InvalidRequestException() {
}

} /* namespace httphelper */
