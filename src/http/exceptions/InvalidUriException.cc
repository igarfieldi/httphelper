/*
 * InvalidUriException.cc
 *
 *  Author: Florian Bethe
 */

#include "http/exceptions/InvalidUriException.h"

namespace httphelper {

InvalidUriException::InvalidUriException(const std::string& msg) :
		InvalidRequestException(msg) {
}

} /* namespace httphelper */
