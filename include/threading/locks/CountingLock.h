/*
 * CountingLock.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_LOCKS_COUNTINGLOCK_H_
#define THREADUTILS_THREADING_LOCKS_COUNTINGLOCK_H_

#include "threading/locks/Lock.h"
#include <mutex>
#include <condition_variable>

namespace threadutils {

class CountingLock :
		public Lock {
protected:
	size_t currLocks;
	size_t maxLocks;

	std::mutex guardMutex;
	std::condition_variable cvLock;

public:
	CountingLock(size_t maxLocks);
	virtual ~CountingLock();

	virtual void lock();
	virtual void unlock();
};

} /* namespace threadutils */

#endif /* THREADUTILS_THREADING_LOCKS_COUNTINGLOCK_H_ */
