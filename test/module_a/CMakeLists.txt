find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

add_executable(a1_unittest a1_unittest.cc)
target_link_libraries(a1_unittest GTest::gtest_main AbcFunctions)

include(GoogleTest)
gtest_discover_tests(a1_unittest)

add_executable(a1_benchmark a1_benchmark.cc)
target_link_libraries(a1_benchmark benchmark::benchmark AbcFunctions)