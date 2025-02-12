find_package(Boost CONFIG REQUIRED COMPONENTS
             date_time regex)
find_package(fmt CONFIG REQUIRED)
find_package(unofficial-concurrentqueue CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED core imgcodecs highgui)
find_path(READERWRITERQUEUE_INCLUDE_DIRS "readerwriterqueue")

add_library(AbcFunctions SHARED abc.cc)

target_include_directories(AbcFunctions PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${READERWRITERQUEUE_INCLUDE_DIRS}"
    "${OpenCV_INCLUDE_DIRS}"
)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
target_link_libraries(AbcFunctions ${OpenCV_LIBS} Boost::date_time Boost::regex unofficial::concurrentqueue::concurrentqueue fmt::fmt)

set(installable_libs AbcFunctions)
install(TARGETS ${installable_libs} DESTINATION lib/pro/module_a)
install(FILES abc.h DESTINATION include/pro/module_a)