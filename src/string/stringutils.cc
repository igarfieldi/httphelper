/*
 * stringutils.cc
 *
 *  Author: Florian Bethe
 */

#include "string/stringutils.h"
#include <algorithm>

namespace strutils {

std::vector<std::string> stringSplit(const std::string& str, const std::string& delim) {
	std::vector<std::string> tokens;

	size_t oldIndex = 0;
	size_t newIndex = 0;

	while((newIndex = str.find(delim, oldIndex)) != std::string::npos) {
		tokens.push_back(str.substr(oldIndex, newIndex-oldIndex));
		oldIndex = newIndex + delim.size();
	}

	tokens.push_back(str.substr(oldIndex, str.length() - oldIndex));

	return tokens;
}

std::vector<std::string> stringSplit(const std::string& str,
		const std::string& delim, size_t maxSplits) {
	std::vector<std::string> tokens;

	size_t oldIndex = 0;
	size_t newIndex = 0;
	size_t splitCounter = 0;

	while((splitCounter++ < maxSplits) &&
			(newIndex = str.find(delim, oldIndex)) != std::string::npos) {
		tokens.push_back(str.substr(oldIndex, newIndex-oldIndex));
		oldIndex = newIndex + delim.size();
	}

	tokens.push_back(str.substr(oldIndex, str.length() - oldIndex));

	return tokens;
}

} /* namespace strutils */
