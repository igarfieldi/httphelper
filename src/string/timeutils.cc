/*
 * timeutils.cc
 *
 *  Author: Florian Bethe
 */

#include "string/timeutils.h"
#include "string/stringutils.h"
#include <time.h>
#include <sys/time.h>

namespace strutils {

std::string getCurrentTimeString() {
	time_t rawTime;
	struct tm* localTime;
	time(&rawTime);
	localTime = localtime(&rawTime);
	// No need to free/delete the char-pointer (it's internal as static)
	// TODO: what about the time struct?

	std::string timeString(asctime(localTime));
	return stringSplit(timeString, "\n", 1)[0];
}

unsigned long long getUnixMilliSeconds() {
	struct timeval timeStruct;
	gettimeofday(&timeStruct, NULL);

	return static_cast<unsigned long long>(timeStruct.tv_sec) * 1000 +
			static_cast<unsigned long long>(timeStruct.tv_usec) / 1000;
}

} /* namespace strutils */
