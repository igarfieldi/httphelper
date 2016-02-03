/*
 * GeneralGeader.cc
 *
 *  Author: Florian Bethe
 */

#include "http/headers/GeneralHeader.h"

namespace httphelper {

const std::string GeneralHeader::CACHE_CONTROL		= "cache-control";
const std::string GeneralHeader::CONNECTION			= "connection";
const std::string GeneralHeader::DATE				= "date";
const std::string GeneralHeader::PRAGMA				= "pragma";
const std::string GeneralHeader::TRAILER			= "trailer";
const std::string GeneralHeader::TRANSFER_ENCODING	= "transfer-encoding";
const std::string GeneralHeader::UPGRADE			= "upgrade";
const std::string GeneralHeader::VIA				= "via";
const std::string GeneralHeader::WARNING			= "warning";


GeneralHeader::GeneralHeader() : Header() {
	fields.insert(std::make_pair(GeneralHeader::CACHE_CONTROL,		std::string()));
	fields.insert(std::make_pair(GeneralHeader::CONNECTION,			std::string()));
	fields.insert(std::make_pair(GeneralHeader::DATE,				std::string()));
	fields.insert(std::make_pair(GeneralHeader::PRAGMA,				std::string()));
	fields.insert(std::make_pair(GeneralHeader::TRAILER,			std::string()));
	fields.insert(std::make_pair(GeneralHeader::TRANSFER_ENCODING,	std::string()));
	fields.insert(std::make_pair(GeneralHeader::UPGRADE,			std::string()));
	fields.insert(std::make_pair(GeneralHeader::VIA,				std::string()));
	fields.insert(std::make_pair(GeneralHeader::WARNING,			std::string()));
}

GeneralHeader::~GeneralHeader() {
}

} /* namespace httphelper */
