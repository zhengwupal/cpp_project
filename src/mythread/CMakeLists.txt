file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(mythread ${SRC_LIST})

target_include_directories(mythread PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(mythread pthread)

set(installable_libs mythread)
install(TARGETS ${installable_libs} DESTINATION lib/pro/mythread)
file(GLOB INCLUDE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/mythread/*.h")
install(FILES ${INCLUDE_LIST} DESTINATION include/pro/mythread)