/*
 * RequestHeader.cc
 *
 *  Author: Florian Bethe
 */

#include "http/headers/RequestHeader.h"

namespace httphelper {

const std::string RequestHeader::ACCEPT					= "accept";
const std::string RequestHeader::ACCEPT_CHARSET			= "accept-charset";
const std::string RequestHeader::ACCEPT_ENCODING		= "accept-encoding";
const std::string RequestHeader::ACCEPT_LANGUAGE		= "accept-language";
const std::string RequestHeader::AUTHORIZATION			= "authorization";
const std::string RequestHeader::EXPECT					= "expect";
const std::string RequestHeader::FROM					= "from";
const std::string RequestHeader::HOST					= "host";
const std::string RequestHeader::IF_MATCH				= "if-match";
const std::string RequestHeader::IF_MODIFIED_SINCE		= "if-modified-since";
const std::string RequestHeader::IF_NONE_MATCH			= "if-none-match";
const std::string RequestHeader::IF_RANGE				= "if-range";
const std::string RequestHeader::IF_UNMODIFIED_SINCE	= "if-unmodified-since";
const std::string RequestHeader::MAX_FORWARDS			= "max-forwards";
const std::string RequestHeader::PROXY_AUTHORIZATION	= "proxy-authorization";
const std::string RequestHeader::RANGE					= "range";
const std::string RequestHeader::REFERER				= "referer";
const std::string RequestHeader::TE						= "te";
const std::string RequestHeader::USER_AGENT				= "user-agent";

RequestHeader::RequestHeader() : GeneralHeader(), EntityHeader() {
	fields.insert(std::make_pair(RequestHeader::ACCEPT,					std::string()));
	fields.insert(std::make_pair(RequestHeader::ACCEPT_CHARSET,			std::string()));
	fields.insert(std::make_pair(RequestHeader::ACCEPT_ENCODING,		std::string()));
	fields.insert(std::make_pair(RequestHeader::ACCEPT_LANGUAGE,		std::string()));
	fields.insert(std::make_pair(RequestHeader::AUTHORIZATION,			std::string()));
	fields.insert(std::make_pair(RequestHeader::EXPECT,					std::string()));
	fields.insert(std::make_pair(RequestHeader::FROM,					std::string()));
	fields.insert(std::make_pair(RequestHeader::HOST,					std::string()));
	fields.insert(std::make_pair(RequestHeader::IF_MATCH,				std::string()));
	fields.insert(std::make_pair(RequestHeader::IF_MODIFIED_SINCE,		std::string()));
	fields.insert(std::make_pair(RequestHeader::IF_NONE_MATCH,			std::string()));
	fields.insert(std::make_pair(RequestHeader::IF_RANGE,				std::string()));
	fields.insert(std::make_pair(RequestHeader::IF_UNMODIFIED_SINCE,	std::string()));
	fields.insert(std::make_pair(RequestHeader::MAX_FORWARDS,			std::string()));
	fields.insert(std::make_pair(RequestHeader::MAX_FORWARDS,			std::string()));
	fields.insert(std::make_pair(RequestHeader::PROXY_AUTHORIZATION,	std::string()));
	fields.insert(std::make_pair(RequestHeader::RANGE,					std::string()));
	fields.insert(std::make_pair(RequestHeader::REFERER,				std::string()));
	fields.insert(std::make_pair(RequestHeader::TE,						std::string()));
	fields.insert(std::make_pair(RequestHeader::USER_AGENT,				std::string()));
}

RequestHeader::~RequestHeader() {
}

} /* namespace httphelper */
