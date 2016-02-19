/*
 * WaitLock.cc
 *
 *  Author: Florian Bethe
 */

#include "threading/locks/WaitLock.h"

namespace threadutils {

WaitLock::WaitLock() :
		locked(false) {
}

WaitLock::~WaitLock() {
}

void WaitLock::lock() {
	std::unique_lock<std::mutex> watchLock(lockMutex);

	if(locked)
		lockCv.wait(watchLock, [this](){ return !locked; });
	else
		locked = true;
}

void WaitLock::unlock() {
	std::unique_lock<std::mutex> watchLock(lockMutex);

	lockCv.notify_one();
}

} /* namespace threadutils */
