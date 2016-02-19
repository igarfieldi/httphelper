/*
 * OrderedLock.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_LOCKS_ORDEREDLOCK_H_
#define THREADUTILS_THREADING_LOCKS_ORDEREDLOCK_H_

#include "threading/locks/Lock.h"
#include <queue>
#include <mutex>
#include <condition_variable>

namespace threadutils {

class OrderedLock :
		public Lock {
protected:
	bool locked;
	bool threadWorking;
	std::mutex queueGuard;
	std::queue<std::condition_variable*> cvQueue;

public:
	OrderedLock();
	virtual ~OrderedLock();

	void lock();
	void unlock();
};

} /* namespace cellauto */

#endif /* THREADUTILS_THREADING_LOCKS_ORDEREDLOCK_H_ */
