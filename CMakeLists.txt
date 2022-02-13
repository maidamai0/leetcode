cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT} CXX)

# cxx standard
set(CMAKE_CXX_STANDARD 20)

find_program(conan_exe conan conan.exe DOC "conan python executable")
if(conan_exe)
    message(STATUS "Found conan: ${conan_exe}")
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

    if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        message(STATUS  "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD
           "https://raw.githubusercontent.com/conan-io/cmake-conan/release/0.17/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            SHOW_PROGRESS
        )
    
        include(${CMAKE_BINARY_DIR}/conan.cmake)
        conan_cmake_configure(REQUIRES
            doctest/2.4.6
            fmt/8.1.1
            magic_enum/0.7.3
            GENERATORS cmake_find_package
        )

        conan_cmake_autodetect(settings)
        conan_cmake_install(PATH_OR_REFERENCE .
                            BUILD missing
                            REMOTE conancenter
                            SETTINGS ${settings})
    endif()
else()
    message(WARNING "conan.exe not found, some dependencies will not be installed automatically")
endif()

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
