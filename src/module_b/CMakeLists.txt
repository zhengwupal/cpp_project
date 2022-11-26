find_package(Boost REQUIRED COMPONENTS date_time)

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

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.2
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        9.1.0
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG        yaml-cpp-0.7.0
)
FetchContent_MakeAvailable(yaml-cpp)

add_library(OptFunctions def.cc)

target_include_directories(OptFunctions PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(OptFunctions Boost::date_time AbcFunctions nlohmann_json::nlohmann_json yaml-cpp fmt::fmt)

set(installable_libs OptFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/pro/module_b)
install(FILES def.h DESTINATION include/pro/module_b)