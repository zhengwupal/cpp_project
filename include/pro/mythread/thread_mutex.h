#ifndef INCLUDE_PRO_MYTHREAD_THREAD_MUTEX_H_
#define INCLUDE_PRO_MYTHREAD_THREAD_MUTEX_H_

#include <iostream>
#include <mutex>

class ThreadMutex {
 public:
  ThreadMutex(std::mutex& mtx) : mtx_(mtx) {
    mtx_.lock();
    std::cout << "Lock" << std::endl;
  };
  ~ThreadMutex() {
    mtx_.unlock();
    std::cout << "Unlock" << std::endl;
  };

 private:
  std::mutex& mtx_;
};

#endif  // INCLUDE_PRO_MYTHREAD_THREAD_MUTEX_H_