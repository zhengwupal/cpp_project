#include "pro/mythread/thread_base.h"

#include <gtest/gtest.h>

#include <iostream>
#include <mutex>
#include <thread>

static std::mutex mtx;

void AddTask(int num) {
  const std::lock_guard<std::mutex> lock(mtx);
  for (size_t i = 0; i < num; i++) {
    std::cout << "i: " << i << std::endl;
  }
  std::cout << "========1=========" << std::endl;
  for (size_t i = 0; i < num; i++) {
    std::cout << "num: " << num << std::endl;
  }
  std::cout << "========2=========" << std::endl;
}

void ThreadBase::MutexTest() {
  std::thread t1(AddTask, 10);
  std::thread t2(AddTask, 8);
  t1.join();
  t2.join();
}

namespace {

TEST(ThreadBaseTest, MutexTest) {
  ThreadBase tb;
  tb.MutexTest();
}

}  // namespace