find_package(Boost REQUIRED COMPONENTS
             date_time)

add_library(AbcFunctions abc.cc)

target_include_directories(AbcFunctions PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(AbcFunctions Boost::date_time readerwriterqueue concurrentqueue fmt::fmt)

set(installable_libs AbcFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/pro/module_a)
install(FILES abc.h DESTINATION include/pro/module_a)