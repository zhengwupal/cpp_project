#include "pro/mythread/lock.h"

#include <gtest/gtest.h>

#include <iostream>

namespace {

TEST(Lock, ConditionVariable) {
  Lock l;
  l.ConditionVariable();
}

}  // namespace