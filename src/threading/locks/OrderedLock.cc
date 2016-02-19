/*
 * OrderedLock.cc
 *
 *  Author: Florian Bethe
 */

#include "threading/locks/OrderedLock.h"

namespace threadutils {

OrderedLock::OrderedLock() :
		Lock(), locked(false), threadWorking(false),
		queueGuard(), cvQueue() {
}

OrderedLock::~OrderedLock() {
}

void OrderedLock::lock() {
	std::unique_lock<std::mutex> watchLock(queueGuard);

	if(locked) {
		std::condition_variable currCv;

		cvQueue.push(&currCv);

		currCv.wait(watchLock, [this, &currCv](){ return !threadWorking && (cvQueue.front() == &currCv); });
		cvQueue.pop();
	} else
		locked = true;

	threadWorking = true;
}

void OrderedLock::unlock() {
	std::unique_lock<std::mutex> watchLock(queueGuard);

	if(cvQueue.empty())
		locked = false;
	else {
		cvQueue.front()->notify_one();
	}

	threadWorking = false;
}

} /* namespace cellauto */
