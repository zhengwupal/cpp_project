cmake_minimum_required(VERSION 3.15)

project(CppProject VERSION 1.0 LANGUAGES C CXX)
# project(cpp_primer VERSION 1.0 LANGUAGES C CXX CUDA)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_14)

configure_file(CppProjectConfig.h.in CppProjectConfig.h)

add_subdirectory(src/module_a)
add_subdirectory(src/module_b)
list(APPEND EXTRA_LIBS AbcFunctions OptFunctions)

add_executable(main src/main.cc)
target_link_libraries(main PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

target_include_directories(main PUBLIC 
    "${PROJECT_BINARY_DIR}"
)

install(TARGETS main DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/CppProjectConfig.h"
    DESTINATION include
)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${CppProject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CppProject_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)

# # install the configuration targets
# install(EXPORT AbcFunctionsTargets
#     FILE AbcFunctionsTargets.cmake
#     DESTINATION lib/cmake/AbcFunctions
# )

# include(CMakePackageConfigHelpers)
# # generate the config file that is includes the exports
# configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
#     "${CMAKE_CURRENT_BINARY_DIR}/AbcFunctionsConfig.cmake"
#     INSTALL_DESTINATION "lib/cmake/example"
#     NO_SET_AND_CHECK_MACRO
#     NO_CHECK_REQUIRED_COMPONENTS_MACRO
# )
# # generate the version file for the config file
# write_basic_package_version_file(
#     "${CMAKE_CURRENT_BINARY_DIR}/AbcFunctionsConfigVersion.cmake"
#     VERSION "${CppProject_VERSION_MAJOR}.${CppProject_VERSION_MINOR}"
#     COMPATIBILITY AnyNewerVersion
# )

# # install the generated configuration files
# install(FILES
#     ${CMAKE_CURRENT_BINARY_DIR}/AbcFunctionsConfig.cmake
#     ${CMAKE_CURRENT_BINARY_DIR}/AbcFunctionsConfigVersion.cmake
#     DESTINATION lib/cmake/AbcFunctions
# )

# # generate the export targets for the build tree
# # needs to be after the install(TARGETS ) command
# export(EXPORT AbcFunctionsTargets
#     FILE "${CMAKE_CURRENT_BINARY_DIR}/AbcFunctionsTargets.cmake"
# )