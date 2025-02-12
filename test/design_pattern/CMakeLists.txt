find_package(GTest CONFIG REQUIRED)

add_executable(strategy_unittest strategy_unittest.cc)
target_link_libraries(strategy_unittest GTest::gtest_main design_pattern)

include(GoogleTest)
gtest_discover_tests(strategy_unittest)
