cmake_minimum_required(VERSION 2.8)
project(tao)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAG "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(LIB_SRC
    tao/log.cpp
    tao/util.cpp
    tao/config.cpp
    )

add_library(tao SHARED ${LIB_SRC})
#add_library(tao_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (tao_static PROPERTIES OUTPUT_NAME "tao")

add_executable(test tests/test.cpp)
add_dependencies(test tao)
target_link_libraries(test tao)

add_executable(test_config tests/test_config.cpp)
add_dependencies(test_config tao)
target_link_libraries(test_config tao)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
