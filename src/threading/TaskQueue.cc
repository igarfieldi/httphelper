/*
 * TaskQueue.cc
 *
 *  Author: Florian Bethe
 */

#include "threading/TaskQueue.h"
#include <iostream>

namespace threadutils {

TaskQueue::TaskQueue() :
		TaskQueue(std::max<size_t>(std::thread::hardware_concurrency(), 1), 0) {

}

TaskQueue::TaskQueue(size_t queueLimit) :
		TaskQueue(std::max<size_t>(std::thread::hardware_concurrency(), 1), queueLimit) {

}

TaskQueue::TaskQueue(size_t workerLimit, size_t queueLimit) :
		workerLimit(std::max<size_t>(workerLimit, 1)), queueLimit(queueLimit),
		workers(), funcQueue(), halt(false), busyWorkers(0) {
	for(size_t i = 0; i < workerLimit; i++)
		workers.emplace_back(std::thread(&TaskQueue::executeWorker, this));
}

TaskQueue::~TaskQueue() {
	stop();
}

void TaskQueue::start() {
	this->start(workerLimit);
}

void TaskQueue::start(size_t workerLimit) {
	workerLimit = std::max<size_t>(workerLimit, 1);
	if(this->workerLimit != workerLimit) {
		if(!halt)
			this->stop();

		this->workerLimit = workerLimit;
	}

	if(halt) {
		halt = false;
		workers = std::vector<std::thread>();
		for(size_t i = 0; i < this->workerLimit; i++)
			workers.emplace_back(std::thread(&TaskQueue::executeWorker, this));
	}
}

void TaskQueue::stop() {
	halt = true;

	queueEmptyCv.notify_all();

	for(std::thread &thread : workers) {
		if(thread.joinable())
			thread.join();
	}
}

void TaskQueue::waitForIdle() {
	std::unique_lock<std::mutex> watchLock(queueMutex);

	threadsIdleCv.wait(watchLock, [this](){ return (busyWorkers == 0) && funcQueue.empty(); });
}

void TaskQueue::executeWorker() {
	while(true) {
		std::unique_lock<std::mutex> watchLock(queueMutex);
		if(funcQueue.empty())
			queueEmptyCv.wait(watchLock, [this](){ return !funcQueue.empty() || halt; });

		if(halt)
			break;
		else {
			++busyWorkers;
			std::function<void()> currFunc = funcQueue.front();
			funcQueue.pop();

			watchLock.unlock();
			currFunc();

			watchLock.lock();
			--busyWorkers;
			threadsIdleCv.notify_one();
		}
	}
}

template <>
void TaskQueue::executeFunction<void>(std::function<void()> func, std::promise<void>* promise) {
	func();
	promise->set_value();
}

} /* namespace threadutils */
