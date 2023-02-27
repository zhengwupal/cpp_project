file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(design_pattern ${SRC_LIST})

target_include_directories(design_pattern PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(design_pattern pthread)

set(installable_libs design_pattern)
install(TARGETS ${installable_libs} DESTINATION lib/pro/design_pattern)
file(GLOB INCLUDE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/design_pattern/*.h")
install(FILES ${INCLUDE_LIST} DESTINATION include/pro/design_pattern)