file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(base ${SRC_LIST})

target_include_directories(base PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(base fmt::fmt)

install(TARGETS base DESTINATION lib/pro/base)

file(GLOB INC_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/pro/base/*.h")
install(FILES INC_LIST DESTINATION include/pro/base)