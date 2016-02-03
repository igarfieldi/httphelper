/*
 * ResponseHeader.cpp
 *
 *  Author: Florian Bethe
 */

#include "http/headers/ResponseHeader.h"

namespace httphelper {

const std::string ResponseHeader::ACCEPT_RANGES			= "accept-ranges";
const std::string ResponseHeader::AGE					= "age";
const std::string ResponseHeader::ETAG					= "etag";
const std::string ResponseHeader::LOCATION				= "location";
const std::string ResponseHeader::PROXY_AUTHENTICATE	= "proxy-authenticate";
const std::string ResponseHeader::RETRY_AFTER			= "retry-after";
const std::string ResponseHeader::SERVER				= "server";
const std::string ResponseHeader::VARY					= "vary";
const std::string ResponseHeader::WWW_AUTHENTICATE		= "www-authenticate";


ResponseHeader::ResponseHeader() : GeneralHeader(), EntityHeader() {
	fields.insert(std::make_pair(ResponseHeader::ACCEPT_RANGES,			std::string()));
	fields.insert(std::make_pair(ResponseHeader::AGE,					std::string()));
	fields.insert(std::make_pair(ResponseHeader::ETAG,					std::string()));
	fields.insert(std::make_pair(ResponseHeader::LOCATION,				std::string()));
	fields.insert(std::make_pair(ResponseHeader::PROXY_AUTHENTICATE,	std::string()));
	fields.insert(std::make_pair(ResponseHeader::RETRY_AFTER,			std::string()));
	fields.insert(std::make_pair(ResponseHeader::SERVER,				std::string()));
	fields.insert(std::make_pair(ResponseHeader::VARY,					std::string()));
	fields.insert(std::make_pair(ResponseHeader::WWW_AUTHENTICATE,		std::string()));
}

ResponseHeader::~ResponseHeader() {
}

} /* namespace httphelper */
