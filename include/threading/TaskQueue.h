/*
 * TaskQueue.h
 *
 *  Author: Florian Bethe
 */

#ifndef THREADUTILS_THREADING_TASKQUEUE_H_
#define THREADUTILS_THREADING_TASKQUEUE_H_

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace threadutils {

class TaskQueue {
protected:
	size_t workerLimit, queueLimit;
	std::vector<std::thread> workers;
	std::queue<std::function<void()>> funcQueue;

	std::mutex queueMutex;
	std::condition_variable queueEmptyCv, threadsIdleCv;

	std::atomic<bool> halt;
	std::atomic<size_t> busyWorkers;

	void executeWorker();

public:
	TaskQueue();
	TaskQueue(size_t queueLimit);
	TaskQueue(size_t workerLimit, size_t queueLimit);
	virtual ~TaskQueue();

	void start();
	void start(size_t workerLimit);

	void stop();

	void waitForIdle();

	template < class R, class... Args >
	std::future<R> queue(std::function<R(Args...)> func, Args... args) {
		if(halt)
			throw std::runtime_error("Tried to add task to halted task queue!");
		std::promise<R>* promise = new std::promise<R>();
		std::future<R> result = promise->get_future();

		std::unique_lock<std::mutex> watchLock(queueMutex);

		if(busyWorkers >= queueLimit)
			threadsIdleCv.wait(watchLock, [this](){ return (queueLimit == 0) || (busyWorkers < queueLimit); });

		// TODO: expand template in capture
		funcQueue.emplace([this, promise, func, args...](){
			std::function<R()> boundFunc = std::bind(func, args...);
			executeFunction(boundFunc, promise);

			delete promise;
		});

		queueEmptyCv.notify_one();

		return std::move(result);
	}

	template < class R >
	void executeFunction(std::function<R()> func, std::promise<R>* promise) {
		promise->set_value(func());
	}
};

template <>
void TaskQueue::executeFunction<void>(std::function<void()> func, std::promise<void>* promise);

} /* namespace threadutils */

#endif /* THREADUTILS_THREADING_TASKQUEUE_H_ */
