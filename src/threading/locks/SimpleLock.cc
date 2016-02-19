/*
 * SimpleLock.cc
 *
 *  Author: Florian Bethe
 */

#include "threading/locks/SimpleLock.h"

namespace threadutils {

SimpleLock::SimpleLock() :
		Lock(), watchLock(lockMutex, std::defer_lock) {
}

SimpleLock::~SimpleLock() {
}

void SimpleLock::lock() {
	watchLock.lock();
}

void SimpleLock::unlock() {
	watchLock.unlock();
}

} /* namespace threadutils */
