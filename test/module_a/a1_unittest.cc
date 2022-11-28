#include <gtest/gtest.h>

#include "pro/module_a/abc.h"
namespace {

TEST(MysqrtTest, Sample) { EXPECT_EQ(2, mysqrt(4)); }

TEST(MysqrtTest, Negative) { EXPECT_EQ(0, mysqrt(-1)); }

}  // namespace