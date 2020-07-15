cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT} CXX)

# cxx standard
# TODO use cxx20 when doctest is updated to 2.40
# doctest 2.37 in vcpkg has a bug of std::uncaught_exception
# see https://github.com/onqtam/doctest/issues/333 for detail
set(CMAKE_CXX_STANDARD 17)

# include(Dart)

enable_testing()

# for doctest
add_compile_definitions("DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN")
find_package(doctest CONFIG REQUIRED)
link_libraries(doctest::doctest)

# for magic enum
find_package(magic_enum CONFIG REQUIRED)
link_libraries(magic_enum::magic_enum)

# time measure
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/time_measure)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/time_measure/include)

link_libraries(time_measurement)

# fmt
find_package(fmt CONFIG REQUIRED)
link_libraries(fmt::fmt)

file(GLOB srcs "*.cpp")
foreach(src ${srcs})
    get_filename_component(TARGET ${src} NAME_WLE)
    message(STATUS "target ${TARGET} added")
    add_executable(${TARGET} ${src})
    add_test(${TARGET}_test ${TARGET})   
endforeach()
