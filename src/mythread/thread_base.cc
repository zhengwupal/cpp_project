#include "pro/mythread/thread_base.h"

#include <iostream>
#include <mutex>
#include <thread>

#include "pro/mythread/thread_mutex.h"

static std::mutex mtx;
void PrintTask(int num) {
  // for (size_t i = 0; i < num; i++) {
  //   std::cout << "num: " << i << std::endl;
  // }
  // std::cout << "=================" << std::endl;

  ThreadMutex lock(mtx);
  for (size_t i = 0; i < num; i++) {
    std::cout << "num: " << num << std::endl;
  }

  std::cout << "child thread " << std::this_thread::get_id() << std::endl;
}

void ThreadBase::BaseTest() {
  std::thread t1(PrintTask, 10);
  std::thread t2(PrintTask, 8);
  // std::cout << "main thread id " << t1.get_id() << std::endl;
  // std::cout << "main thread id " << std::this_thread::get_id() << std::endl;
  t1.join();
  t2.join();
  // std::cout << "main thread " << std::this_thread::get_id() << std::endl;
}
