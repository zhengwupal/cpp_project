add_subdirectory(thirdparty)
add_subdirectory(module_a)
add_subdirectory(module_b)
list(APPEND LIBS AbcFunctions OptFunctions)

add_executable(main main.cc)
target_link_libraries(main PUBLIC ${LIBS})

target_include_directories(main PUBLIC 
    "${PROJECT_BINARY_DIR}"
)

install(TARGETS main DESTINATION bin)