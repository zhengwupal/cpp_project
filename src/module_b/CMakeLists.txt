set(CMAKE_MODULE_PATH "/home/zhengwu/projects/CMake/Modules")
find_package(Boost REQUIRED COMPONENTS date_time)
set(nlohmann_json_DIR "/home/zhengwu/projects/cpp_project/src/thirdparty/json/build")
find_package(nlohmann_json REQUIRED)
if(nlohmann_json_FOUND)
    message("-- Found nlohmann_json")
endif(nlohmann_json_FOUND)
set(yaml-cpp_DIR "/home/zhengwu/projects/cpp_project/lib/cmake/yaml-cpp")
find_package(yaml-cpp REQUIRED)
if(yaml-cpp_FOUND)
    message("-- Found yaml-cpp")
endif(yaml-cpp_FOUND)

add_library(OptFunctions def.cc)

target_include_directories(OptFunctions
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(OptFunctions Boost::date_time AbcFunctions nlohmann_json::nlohmann_json yaml-cpp)

set(installable_libs OptFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/module_b)
install(FILES def.h DESTINATION include/module_b)