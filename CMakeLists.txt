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

file(GLOB_RECURSE SOURCE_FILES "src/*.cc")
foreach(SOURCE_FILE ${SOURCE_FILES})
  get_filename_component(TARGET_NAME "${SOURCE_FILE}" NAME_WE)
  add_executable(${TARGET_NAME} "${SOURCE_FILE}") 
  target_link_libraries(${TARGET_NAME} PRIVATE Threads::Threads)
  if(TARGET_NAME MATCHES "test_*")
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
  endif()
endforeach()
