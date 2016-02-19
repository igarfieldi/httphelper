/*
 * BaseHeader.cc
 *
 *  Author: Florian Bethe
 */

#include "http/headers/Header.h"
#include "string/stringutils.h"
#include <vector>
#include <algorithm>

namespace httphelper {

Header::Header() : fields() {
}

Header::~Header() {
}

bool Header::setField(const std::string& fieldName, const std::string& val) {
	if(fields.find(fieldName) != fields.end()) {
		fields[fieldName] = val;
		return true;
	}

	return false;
}

bool Header::clearField(const std::string& fieldName) {
	if(fields.find(fieldName) != fields.end()) {
		fields[fieldName] = "";
		return true;
	}

	return false;
}

bool Header::addToField(const std::string& fieldName, const std::string& val) {
	if(fields.find(fieldName) != fields.end()) {
		fields[fieldName] += val;
		return true;
	}

	return false;
}

std::string Header::getField(const std::string& fieldName) const {
	return fields.at(fieldName);
}

Header& Header::parse(const std::string& msg) {
	std::vector<std::string> tokens = strutils::stringSplit(msg, "\r\n");

	for(std::vector<std::string>::const_iterator iter = tokens.begin();
			iter != tokens.end(); iter++) {
		std::vector<std::string> field = strutils::stringSplit(*iter, ":", 1);

		// We are generous... header entries without ':' are just ignored
		// instead of throwing an exception
		if(field.size() < 2)
			continue;

		// Transform the field name to lower case for recognition
		std::transform(field[0].begin(), field[0].end(), field[0].begin(), ::tolower);

		// Remmove leading/trailing whitespaces
		size_t firstNonWhite = field[1].find_first_not_of(" \t");
		size_t lastNonWhite = field[1].find_last_not_of(" \t");

		this->addToField(field[0], field[1].substr(firstNonWhite, lastNonWhite - firstNonWhite + 1));
	}

	return *this;
}

std::string Header::toString() const {
	std::string header;

	for(std::map<std::string, std::string>::const_iterator iter = fields.begin();
			iter != fields.end(); ++iter) {
		if(!std::get<1>(*iter).empty())
			header += std::get<0>(*iter) +
					std::string(": ") +
					std::get<1>(*iter) +
					std::string("\r\n");
	}

	return header;
}

} /* namespace httphelper */
