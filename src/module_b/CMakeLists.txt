find_package(Boost CONFIG COMPONENTS date_time)
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# set(thirdparty_DIR "/home/zhengwu/projects/cpp_project/src/thirdparty")
# set(nlohmann_json_DIR "${thirdparty_DIR}/json/build")
# find_package(nlohmann_json REQUIRED)
# if(nlohmann_json_FOUND)
#     message("-- Found nlohmann_json")
# endif(nlohmann_json_FOUND)

# set(yaml-cpp_DIR "${thirdparty_DIR}/yaml-cpp/build/lib/cmake/yaml-cpp")
# find_package(yaml-cpp REQUIRED)
# if(yaml-cpp_FOUND)
#     message("-- Found yaml-cpp")
# endif(yaml-cpp_FOUND)

# set(fmt_DIR "${thirdparty_DIR}/fmt/build")
# find_package(fmt REQUIRED)
# if(fmt_FOUND)
#     message("-- Found fmt")
# endif(fmt_FOUND)

add_library(OptFunctions def.cc)

target_include_directories(OptFunctions PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(OptFunctions Boost::date_time AbcFunctions nlohmann_json::nlohmann_json fmt::fmt)

set(installable_libs OptFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/pro/module_b)
install(FILES def.h DESTINATION include/pro/module_b)