/*
 * UnknownHttpVersionException.cc
 *
 *  Author: Florian Bethe
 */

#include "http/exceptions/UnknownHttpVersionException.h"

namespace httphelper {

UnknownHttpVersionException::UnknownHttpVersionException() :
	InvalidRequestException("Unknown http version!") {
}

UnknownHttpVersionException::~UnknownHttpVersionException() {
}

} /* namespace httphelper */
