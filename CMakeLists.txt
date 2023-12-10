cmake_minimum_required(VERSION 3.15)

project(CppProject VERSION 1.2 LANGUAGES C CXX)
# project(cpp_primer VERSION 1.0 LANGUAGES C CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(cppproject_config.h.in cppproject_config.h)

########################################
add_subdirectory(src/base_test)
add_subdirectory(src/class_test)
add_subdirectory(src/module_a)
add_subdirectory(src/module_b)
add_subdirectory(src/mythread)
add_subdirectory(src/design_pattern)
list(APPEND LIBS base_test class_test AbcFunctions OptFunctions mythread design_pattern)

add_executable(main src/main.cc)
target_link_libraries(main PUBLIC ${LIBS})

target_include_directories(main PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
)

install(TARGETS main DESTINATION bin)
########################################

########################################
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.7.1
)
set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_USE_BUNDLED_GTEST OFF)
FetchContent_MakeAvailable(benchmark)

find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

include(CTest)

add_subdirectory(test/module_a)
add_subdirectory(test/module_b)
add_subdirectory(test/mythread)
add_subdirectory(test/design_pattern)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")
INCLUDE(CodeCoverage)
########################################

########################################
install(FILES "${PROJECT_BINARY_DIR}/cppproject_config.h"
    DESTINATION include
)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${CppProject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CppProject_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
########################################
