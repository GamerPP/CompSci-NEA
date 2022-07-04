cmake_minimum_required(VERSION 3.20.0)
set(MAIN_PROJECT "CompSci-NEA")
project(${MAIN_PROJECT} VERSION 0.1.0)

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)

    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        include_directories(${raylib_SOURCE_DIR})

    endif()

endif()


file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp)
add_executable(${MAIN_PROJECT} ${SRC})
target_link_libraries(${MAIN_PROJECT} raylib)

add_custom_command(TARGET ${MAIN_PROJECT} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/Resources)