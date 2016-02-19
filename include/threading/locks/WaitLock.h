/*
 * WaitLock.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_LOCKS_WAITLOCK_H_
#define THREADUTILS_THREADING_LOCKS_WAITLOCK_H_

#include "threading/locks/Lock.h"
#include <mutex>
#include <condition_variable>

namespace threadutils {

class WaitLock: public Lock {
protected:
	bool locked;

	std::mutex lockMutex;
	std::condition_variable lockCv;

public:
	WaitLock();
	virtual ~WaitLock();

	virtual void lock();
	virtual void unlock();
};

} /* namespace threadutils */

#endif /* THREADUTILS_THREADING_LOCKS_WAITLOCK_H_ */
