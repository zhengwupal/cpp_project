file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(ioc ${SRC_LIST})

target_include_directories(ioc PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(ioc nlohmann_json::nlohmann_json)

set(installable_libs ioc)
install(TARGETS ${installable_libs} DESTINATION lib/pro/ioc)
file(GLOB INCLUDE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/ioc/*.h")
install(FILES ${INCLUDE_LIST} DESTINATION include/pro/ioc)