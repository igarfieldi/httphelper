/*
 * timeutils.cc
 *
 *  Author: Florian Bethe
 */

#include "string/timeutils.h"
#include <time.h>

namespace strutils {

std::string getCurrentTimeString() {
	time_t rawTime;
	struct tm* localTime;
	time(&rawTime);
	localTime = localtime(&rawTime);
	// No need to free/delete the char-pointer (it's internal as static)
	// TODO: what about the time struct?

	return std::string(asctime(localTime));
}

} /* namespace strutils */
