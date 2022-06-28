cmake_minimum_required(VERSION 3.20.0)
set(MAIN_PROJECT "CompSci-NEA")
project(${MAIN_PROJECT} VERSION 0.1.0)

find_package(raylib 4.0.0 QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp)
add_executable(${MAIN_PROJECT} ${SRC})
target_link_libraries(${MAIN_PROJECT} raylib)