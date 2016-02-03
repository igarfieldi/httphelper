/*
 * RequestHeader.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_HEADERS_REQUESTHEADER_H_
#define HTTPHELPER_HTTP_HEADERS_REQUESTHEADER_H_

#include "http/headers/EntityHeader.h"
#include "http/headers/GeneralHeader.h"
#include <string>

namespace httphelper {

class RequestHeader :
		public GeneralHeader, public EntityHeader {
public:
	static const std::string ACCEPT;
	static const std::string ACCEPT_CHARSET;
	static const std::string ACCEPT_ENCODING;
	static const std::string ACCEPT_LANGUAGE;
	static const std::string AUTHORIZATION;
	static const std::string EXPECT;
	static const std::string FROM;
	static const std::string HOST;
	static const std::string IF_MATCH;
	static const std::string IF_MODIFIED_SINCE;
	static const std::string IF_NONE_MATCH;
	static const std::string IF_RANGE;
	static const std::string IF_UNMODIFIED_SINCE;
	static const std::string MAX_FORWARDS;
	static const std::string PROXY_AUTHORIZATION;
	static const std::string RANGE;
	static const std::string REFERER;
	static const std::string TE;
	static const std::string USER_AGENT;

	RequestHeader();
	virtual ~RequestHeader();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_HEADERS_REQUESTHEADER_H_ */
