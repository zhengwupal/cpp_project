include(GoogleTest)

# add_executable(thread_base_unittest thread_base_unittest.cc)
# add_executable(mutex_lock_unittest mutex_lock_unittest.cc)
add_executable(lock_unittest lock_unittest.cc)
# target_link_libraries(thread_base_unittest GTest::gtest_main mythread)
# target_link_libraries(mutex_lock_unittest GTest::gtest_main mythread)
target_link_libraries(lock_unittest GTest::gtest_main mythread)

# gtest_discover_tests(thread_base_unittest)
# gtest_discover_tests(mutex_lock_unittest)
gtest_discover_tests(lock_unittest)
