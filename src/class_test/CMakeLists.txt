file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(class_test ${SRC_LIST})

target_include_directories(class_test PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(class_test fmt::fmt)

install(TARGETS class_test DESTINATION lib/pro/class_test)

file(GLOB INC_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/class_test/*.h")
install(FILES INC_LIST DESTINATION include/pro/class_test)