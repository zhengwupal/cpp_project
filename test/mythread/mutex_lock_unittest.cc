#include <gtest/gtest.h>

#include <iostream>
#include <thread>

#include "pro/mythread/task.h"

namespace {

// TEST(ThreadMutexTest, UniqueLock) {
//   Task t;
//   t.Process1();
// }

TEST(ThreadMutexTest, AtomicInt) {
  Task t;
  t.Process2();
}

}  // namespace