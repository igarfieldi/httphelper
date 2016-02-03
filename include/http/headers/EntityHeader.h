/*
 * EntityHeader.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_HEADERS_ENTITYHEADER_H_
#define HTTPHELPER_HTTP_HEADERS_ENTITYHEADER_H_

#include "http/headers/Header.h"
#include <string>

namespace httphelper {

class EntityHeader :
		virtual public Header {
public:
	static const std::string ALLOW;
	static const std::string CONTENT_ENCODING;
	static const std::string CONTENT_LANGUAGE;
	static const std::string CONTENT_LENGTH;
	static const std::string CONTENT_LOCATION;
	static const std::string CONTENT_MD5;
	static const std::string CONTENT_RANGE;
	static const std::string CONTENT_TYPE;
	static const std::string EXPIRES;
	static const std::string LAST_MODIFIED;
	static const std::string EXTENSION_HEADER;

	EntityHeader();
	virtual ~EntityHeader();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_HEADERS_ENTITYHEADER_H_ */
