/*
 * SimpleLock.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_LOCKS_SIMPLELOCK_H_
#define THREADUTILS_THREADING_LOCKS_SIMPLELOCK_H_

#include "threading/locks/Lock.h"
#include <mutex>

namespace threadutils {

class SimpleLock :
		public Lock {
protected:
	std::mutex lockMutex;
	std::unique_lock<std::mutex> watchLock;

public:
	SimpleLock();
	virtual ~SimpleLock();

	virtual void lock();
	virtual void unlock();
};

} /* namespace threadutils */

#endif /* THREADUTILS_THREADING_LOCKS_SIMPLELOCK_H_ */
