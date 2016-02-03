/*
 * BaseHeader.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_HEADERS_HEADER_H_
#define HTTPHELPER_HTTP_HEADERS_HEADER_H_

#include <map>
#include <string>

namespace httphelper {

class Header {
protected:
	std::map<std::string, std::string> fields;

public:
	Header();
	virtual ~Header();

	bool setField(const std::string& fieldName, const std::string& val);
	bool clearField(const std::string& fieldName);
	bool addToField(const std::string& fieldName, const std::string& val);

	std::string getField(const std::string& fieldName) const;

	virtual std::string toString() const;
	virtual void parse(const std::string& msg);
};

} /* namespace httphelper */


#endif /* HTTPHELPER_HTTP_HEADERS_HEADER_H_ */
