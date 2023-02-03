file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(base_test ${SRC_LIST})

target_include_directories(base_test PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(base_test fmt::fmt)

install(TARGETS base_test DESTINATION lib/pro/base_test)

file(GLOB INC_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/base_test/*.h")
install(FILES INC_LIST DESTINATION include/pro/base_test)