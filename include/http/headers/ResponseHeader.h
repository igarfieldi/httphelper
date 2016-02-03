/*
 * ResponseHeader.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_HEADERS_RESPONSEHEADER_H_
#define HTTPHELPER_HTTP_HEADERS_RESPONSEHEADER_H_

#include "http/headers/EntityHeader.h"
#include "http/headers/GeneralHeader.h"
#include <string>

namespace httphelper {

class ResponseHeader :
		public GeneralHeader, public EntityHeader {
public:
	static const std::string ACCEPT_RANGES;
	static const std::string AGE;
	static const std::string ETAG;
	static const std::string LOCATION;
	static const std::string PROXY_AUTHENTICATE;
	static const std::string RETRY_AFTER;
	static const std::string SERVER;
	static const std::string VARY;
	static const std::string WWW_AUTHENTICATE;

	ResponseHeader();
	virtual ~ResponseHeader();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_HEADERS_RESPONSEHEADER_H_ */
