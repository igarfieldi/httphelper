/*
 * GeneralGeader.h
 *
 *  Author: Florian Bethe
 */

#ifndef HTTPHELPER_HTTP_HEADERS_GENERALHEADER_H_
#define HTTPHELPER_HTTP_HEADERS_GENERALHEADER_H_

#include "http/headers/Header.h"
#include <string>

namespace httphelper {

class GeneralHeader :
	virtual public Header {
public:
	static const std::string CACHE_CONTROL;
	static const std::string CONNECTION;
	static const std::string DATE;
	static const std::string PRAGMA;
	static const std::string TRAILER;
	static const std::string TRANSFER_ENCODING;
	static const std::string UPGRADE;
	static const std::string VIA;
	static const std::string WARNING;

	GeneralHeader();
	virtual ~GeneralHeader();
};

} /* namespace httphelper */

#endif /* HTTPHELPER_HTTP_HEADERS_GENERALHEADER_H_ */
