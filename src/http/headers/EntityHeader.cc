/*
 * EntityHeader.cc
 *
 *  Author: Florian Bethe
 */

#include "http/headers/EntityHeader.h"

namespace httphelper {

const std::string EntityHeader::ALLOW				= "allow";
const std::string EntityHeader::CONTENT_ENCODING	= "content-encoding";
const std::string EntityHeader::CONTENT_LANGUAGE	= "content-language";
const std::string EntityHeader::CONTENT_LENGTH		= "content-length";
const std::string EntityHeader::CONTENT_LOCATION	= "content-location";
const std::string EntityHeader::CONTENT_MD5			= "content-md5";
const std::string EntityHeader::CONTENT_RANGE		= "content-range";
const std::string EntityHeader::CONTENT_TYPE		= "content-type";
const std::string EntityHeader::EXPIRES				= "expires";
const std::string EntityHeader::LAST_MODIFIED		= "last-modified";
const std::string EntityHeader::EXTENSION_HEADER	= "extension-header";


EntityHeader::EntityHeader() : Header() {
	fields.insert(std::make_pair(EntityHeader::ALLOW,				std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_ENCODING,	std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_LANGUAGE,	std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_LENGTH,		std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_LOCATION,	std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_MD5,			std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_RANGE,		std::string()));
	fields.insert(std::make_pair(EntityHeader::CONTENT_TYPE,		std::string()));
	fields.insert(std::make_pair(EntityHeader::EXPIRES,				std::string()));
	fields.insert(std::make_pair(EntityHeader::LAST_MODIFIED,		std::string()));
	fields.insert(std::make_pair(EntityHeader::EXTENSION_HEADER,	std::string()));
}

EntityHeader::~EntityHeader() {
}

} /* namespace httphelper */
