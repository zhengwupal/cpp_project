#include "pro/mythread/task.h"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <thread>

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

void Task::AtomicAddTask(int a) {
  for (size_t i = 0; i < 1000000; i++) {
    cd->GetNum()++;
  }
}

void Task::Process1() {
  std::thread t1(&Task::ComputeTask, this, 1, 2);
  std::thread t2(&Task::ComputeTask, this, 3, 4);

  t1.join();
  t2.join();
}

void Task::Process2() {
  std::cout << cd->GetNum() << std::endl;
  std::thread t1(&Task::AtomicAddTask, this, 2);
  std::thread t2(&Task::AtomicAddTask, this, 3);
  std::thread t3(&Task::AtomicAddTask, this, 8);

  t1.join();
  t2.join();
  t3.join();
  std::cout << cd->GetNum() << std::endl;
}