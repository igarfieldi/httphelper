/*
 * CountingLock.cc
 *
 *  Author: Florian Bethe
 */

#include "threading/locks/CountingLock.h"

namespace threadutils {

CountingLock::CountingLock(size_t maxLocks) :
		currLocks(0), maxLocks(maxLocks) {
}

CountingLock::~CountingLock() {
}

void CountingLock::lock() {
	std::unique_lock<std::mutex> watchLock(guardMutex);

	if(currLocks >= maxLocks)
		cvLock.wait(watchLock, [this](){ return currLocks < maxLocks; });

	++currLocks;
}

void CountingLock::unlock() {
	std::unique_lock<std::mutex> watchLock(guardMutex);

	if(currLocks-- >= maxLocks)
		cvLock.notify_one();
}

} /* namespace threadutils */
