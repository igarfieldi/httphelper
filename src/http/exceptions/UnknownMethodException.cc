/*
 * UnknownMethodException.cc
 *
 *  Author: Florian Bethe
 */

#include "http/exceptions/UnknownMethodException.h"

namespace httphelper {

UnknownMethodException::UnknownMethodException() :
	InvalidRequestException("Unknown http request method!") {
}

UnknownMethodException::~UnknownMethodException() {
}

} /* namespace httphelper */
