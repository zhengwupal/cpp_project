#include <gtest/gtest.h>

#include <iostream>
#include <thread>

#include "pro/mythread/task.h"

void Task::ComputeTask(int a, int b) {
  // std::cout << "a + b = " << a + b << std::endl;
  // std::cout << "a - b = " << a - b << std::endl;
  // std::cout << "a * b = " << a * b << std::endl;

  SafeAddTask(a, b);
}

void Task::SafeAddTask(int a, int b) {
  std::unique_lock<std::mutex> lock(mtx_);
  std::cout << "========SafeAddTask START=========" << std::endl;
  std::cout << "a * b = " << a * b << std::endl;
  std::cout << "a / b = " << a / b << std::endl;
  std::cout << "a + b = " << a + b << std::endl;
  std::cout << "a - b = " << a - b << std::endl;
  std::cout << "(a * b) * 10000 / b * 212 + 21398 * 212 - 21123 = "
            << (a * b) * 10000 / b * 212 + 21398 * 212 - 21123 << std::endl;
  std::cout << "========SafeAddTask END=========" << std::endl;
}

void Task::Process() {
  std::thread t1(&Task::ComputeTask, this, 1, 2);
  std::thread t2(&Task::ComputeTask, this, 3, 4);

  t1.join();
  t2.join();
}

namespace {

TEST(ThreadMutexTest, UniqueLock) {
  Task t;
  t.Process();
}

}  // namespace