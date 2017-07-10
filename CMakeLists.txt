cmake_minimum_required(VERSION 3.9.0)

project(Humble-Whole)

option(BUILD_GLFW "build glfw library" ON)
option(ENABLE_VULKAN "enable vulkan api" ON)
option(ENABLE_OPENGL "enable Opengl api" OFF)
option(BUILD_IMEMORY_TESTS "build IMemory tests" OFF)
option(BUILD_TOOLS_TESTS "build Tools tests" OFF)
option(BUILD_HUMBLE_TESTS "build Humble tests" ON)


set(HUMBLE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Humble/include)
set(GLFW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/glfw/include)
set(TOOLS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Tools/include)
set(IMEMORY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/IMemory/include)
set(VGRAPHICAL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/VGraphical/include)

if(ENABLE_VULKAN)
    find_path(_VULKAN_INCLUDE_DIR NAMES vulkan/vulkan.h HINTS
        "$ENV{VULKAN_SDK}/Include"
        "$ENV{VK_SDK_PATH}/Include")
    set(VULKAN_INCLUDE_DIR ${_VULKAN_INCLUDE_DIR})
endif()


if(BUILD_GLFW)
    add_subdirectory(glfw)
endif()


add_subdirectory(VGraphical)
add_subdirectory(Humble)

if(BUILD_IMEMORY_TESTS)
    add_subdirectory(IMemory)
endif()

if(BUILD_TOOLS_TESTS)
    add_subdirectory(Tools)
endif()

if(BUILD_HUMBLE_TESTS)
    add_subdirectory(tests)
endif()