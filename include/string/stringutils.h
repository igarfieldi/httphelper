/*
 * stringutils.h
 *
 *  Author: Florian Bethe
 */

#ifndef STRUTILS_STRING_STRINGUTILS_H_
#define STRUTILS_STRING_STRINGUTILS_H_

#include <vector>
#include <string>

namespace strutils {

std::vector<std::string> stringSplit(const std::string& str, const std::string& delim);
std::vector<std::string> stringSplit(const std::string& str,
		const std::string& delim, size_t maxSplits);

} /* namespace strutils */


#endif /* STRUTILS_STRING_STRINGUTILS_H_ */
