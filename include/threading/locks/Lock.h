/*
 * Lock.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_LOCKS_LOCK_H_
#define THREADUTILS_THREADING_LOCKS_LOCK_H_

namespace threadutils {

class Lock {
public:
	Lock();
	virtual ~Lock();

	virtual void lock() = 0;
	virtual void unlock() = 0;
};

} /* namespace threadutils */

#endif /* THREADUTILS_THREADING_LOCKS_LOCK_H_ */
