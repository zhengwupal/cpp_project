include(GoogleTest)

add_executable(a1_unittest a1_unittest.cc)
target_link_libraries(a1_unittest GTest::gtest_main AbcFunctions)

gtest_discover_tests(a1_unittest WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/test/module_a")