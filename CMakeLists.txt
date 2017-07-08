cmake_minimum_required(VERSION 3.9.0)

project(Humble-Whole)

option(BUILD_GLFW "build glfw library" ON)
option(BUILD_IMEMORY_TESTS "build IMemory tests" OFF)
option(BUILD_TOOLS_TESTS "build Tools tests" OFF)
option(BUILD_HUMBLE_TESTS "build Humble tests" ON)


set(GLFW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/glfw/include)
set(IMEMORY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/IMemory/include)


if(BUILD_GLFW)
    add_subdirectory(glfw)
endif()

add_subdirectory(Humble)

if(BUILD_IMEMORY_TESTS)
    add_subdirectory(IMemory)
endif()

if(BUILD_TOOLS_TESTS)
    add_subdirectory(Tools)
endif()

if(BUILD_HUMBLE_TESTS)
    add_subdirectory(Humble/tests)
endif()