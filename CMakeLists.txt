cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT} CXX)

# cxx standard
set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

find_package(doctest REQUIRED)
add_compile_definitions(DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
link_libraries(doctest::doctest)

find_package(fmt REQUIRED)
link_libraries(fmt::fmt)

find_package(magic_enum REQUIRED)
link_libraries(magic_enum::magic_enum)

if(MSVC)
    add_compile_options(/EHsc /W4 /Zc:__cplusplus)
endif()

if(WIN32)
    add_compile_definitions(UNICODE _UNICODE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()
add_subdirectory(src)
