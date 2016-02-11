/*
 * timeutils.h
 *
 *  Author: Florian Bethe
 */

#ifndef STRUTILS_STRING_TIMEUTILS_H_
#define STRUTILS_STRING_TIMEUTILS_H_

#include <string>

namespace strutils {

	std::string getCurrentTimeString();
	unsigned long long getUnixMilliSeconds();

} /* namespace strutils */

#endif /* STRUTILS_STRING_TIMEUTILS_H_ */
