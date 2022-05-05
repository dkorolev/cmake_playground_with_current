cmake_minimum_required(VERSION 3.14.1)

project(cmake_playground_with_current C CXX)

set (CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(current
                     GIT_REPOSITORY https://github.com/c5t/current
                     GIT_TAG stable_2022_04_10
                     GIT_SHALLOW TRUE
                     GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(current)

include_directories(${current_SOURCE_DIR})

if(NOT WIN32)
add_custom_command(OUTPUT ${current_SOURCE_DIR}/current_build.h
                   WORKING_DIRECTORY ${current_SOURCE_DIR}
                   COMMAND scripts/gen-current-build.sh
                   ARGS current_build.h)
else()
add_custom_command(OUTPUT ${current_SOURCE_DIR}/current_build.h
                   WORKING_DIRECTORY ${current_SOURCE_DIR}
                   COMMAND echo
                   ARGS namespace current::build { constexpr static const char* kGitCommit = "Not here pls."\; } >current_build.h)
endif()
add_custom_target(current_build_h DEPENDS ${current_SOURCE_DIR}/current_build.h)

add_executable(hw0 src/hw0.cc)
target_link_libraries(hw0 PRIVATE Threads::Threads)

add_executable(hw1 src/hw1.cc)
target_link_libraries(hw1 PRIVATE Threads::Threads)

add_executable(hw2 src/hw2.cc)
target_link_libraries(hw2 PRIVATE Threads::Threads)

add_executable(hw3 src/hw3.cc)
add_dependencies(hw3 current_build_h)
target_link_libraries(hw3 PRIVATE Threads::Threads)

add_library(lib_hw4_name src/lib_hw4_name.cc)
add_executable(hw4 src/hw4.cc)
target_link_libraries(hw4 PRIVATE Threads::Threads lib_hw4_name)
