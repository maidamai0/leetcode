cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT} CXX)

# cxx standard
set(CMAKE_CXX_STANDARD 20)

# include(Dart)

enable_testing()

# for doctest
add_compile_definitions("DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/doctest)

# for magic enum
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/magic_enum/include)

# time measure
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/time_measure)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/time_measure/include)

link_libraries(time_measurement)

file(GLOB srcs "*.cpp")
foreach(src ${srcs})
    get_filename_component(TARGET ${src} NAME_WLE)
    message(STATUS "target ${TARGET} added")
    add_executable(${TARGET} ${src})
    add_test(${TARGET}_test ${TARGET})   
endforeach()
