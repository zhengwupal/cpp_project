set(CMAKE_MODULE_PATH "/home/zhengwu/projects/CMake/Modules")
find_package(Boost REQUIRED COMPONENTS
             date_time)

add_library(OptFunctions def.cc)

target_include_directories(OptFunctions
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(OptFunctions Boost::date_time AbcFunctions tutorial_compiler_flags)

set(installable_libs OptFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib/module_b)
install(FILES def.h DESTINATION include/module_b)