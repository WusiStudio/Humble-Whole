cmake_minimum_required(VERSION 3.9.0)

project(Humble-test)

include_directories(include)


if(HUMBLE_INCLUDE_DIR)
    include_directories(${HUMBLE_INCLUDE_DIR})
endif()

if(VULKAN_INCLUDE_DIR)
	include_directories(${VULKAN_INCLUDE_DIR})
endif()

if(GLM_INCLUDE_DIR)
    include_directories(${GLM_INCLUDE_DIR})
endif()

if(GLFW_INCLUDE_DIR)
    include_directories(${GLFW_INCLUDE_DIR})
endif()

if(TOOLS_INCLUDE_DIR)
    include_directories(${TOOLS_INCLUDE_DIR})
endif()

if(IMEMORY_INCLUDE_DIR)
    include_directories(${IMEMORY_INCLUDE_DIR})
endif()

if(VGRAPHICAL_INCLUDE_DIR)
    include_directories(${VGRAPHICAL_INCLUDE_DIR})
endif()

aux_source_directory(src SRCS)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} Humble VGraphical glfw ${VULKAN_LIBRARY})


#输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

#设置编译选项-------------------------------------------
IF(WIN32)
    # DEBUG RELEASE
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -Wall")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -Wall")

ELSEIF(APPLE)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -m64 -std=c++11 -O0 -Wall -g")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -m64 -std=c++11 -O3 -Wall")

ELSEIF(UNIX)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -m64 -std=c++11 -O0 -Wall -g")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -m64 -std=c++11 -O3 -Wall")
ENDIF()