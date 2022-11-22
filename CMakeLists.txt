cmake_minimum_required(VERSION 3.15)

project(CppProject VERSION 1.2 LANGUAGES C CXX)
# project(cpp_primer VERSION 1.0 LANGUAGES C CXX CUDA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(CppProjectConfig.h.in CppProjectConfig.h)

add_subdirectory(src)

install(FILES "${PROJECT_BINARY_DIR}/CppProjectConfig.h"
    DESTINATION include
)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${CppProject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CppProject_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)