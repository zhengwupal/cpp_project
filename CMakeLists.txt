cmake_minimum_required(VERSION 3.15)

project(CppProject VERSION 1.2 LANGUAGES C CXX)
# project(cpp_primer VERSION 1.0 LANGUAGES C CXX CUDA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(cppproject_config.h.in cppproject_config.h)

########################################
add_subdirectory(src/module_a)
add_subdirectory(src/module_b)
list(APPEND LIBS AbcFunctions OptFunctions)

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

enable_testing()

add_subdirectory(test/module_a)
add_subdirectory(test/module_b)
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