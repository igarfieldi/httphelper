/*
 * RequestMethods.cc
 *
 *  Author: Florian Bethe
 */

#include "http/messages/RequestMethod.h"

namespace httphelper {

RequestMethod::RequestMethod(const std::string& name) :
			name(name) {
}

const std::string& RequestMethod::getName() const {
	return name;
}

bool RequestMethod::operator==(const RequestMethod& method) const {
	return name == method.name;
}

bool RequestMethod::operator!=(const RequestMethod& method) const {
	return name != method.name;
}

bool RequestMethod::operator==(const std::string& name) const {
	return this->name == name;
}

bool RequestMethod::operator!=(const std::string& name) const {
	return this->name != name;
}

bool RequestMethod::operator<(const RequestMethod& method) const {
	return name < method.name;
}

bool RequestMethod::operator>(const RequestMethod& method) const {
	return name > method.name;
}

} /* namespace httphelper */
