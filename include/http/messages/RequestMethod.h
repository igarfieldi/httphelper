/*
 * RequestMethods.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_MESSAGES_REQUESTMETHOD_H_
#define HTTPHELPER_HTTP_MESSAGES_REQUESTMETHOD_H_

#include <string>

namespace httphelper {

class RequestMethod {
protected:
	std::string name;

public:
	RequestMethod(const std::string& name);

	const std::string& getName() const;

	bool operator==(const RequestMethod& method) const;
	bool operator!=(const RequestMethod& method) const;
	bool operator==(const std::string& name) const;
	bool operator!=(const std::string& name) const;
	bool operator<(const RequestMethod& method) const;
	bool operator>(const RequestMethod& method) const;
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_MESSAGES_REQUESTMETHOD_H_ */
