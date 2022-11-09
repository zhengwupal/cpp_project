set(CMAKE_MODULE_PATH "/home/zhengwu/projects/CMake/Modules")
find_package(Boost REQUIRED COMPONENTS
             date_time filesystem iostreams regex)

add_library(AbcFunctions abc.cc)

target_include_directories(AbcFunctions
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(AbcFunctions Boost::date_time Boost::regex)

set(installable_libs AbcFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/module_a)
install(FILES abc.h DESTINATION include/module_a)