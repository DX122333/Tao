cmake_minimum_required(VERSION 2.8)
project(tao)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAG "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_library(YAMLCPP yaml-cpp)
message("***", ${YAMLCPP})

set(LIB_SRC
    tao/log.cpp
    tao/util.cpp
    tao/config.cpp
    tao/thread.cpp
    )

add_library(tao SHARED ${LIB_SRC})
#add_library(tao_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (tao_static PROPERTIES OUTPUT_NAME "tao")

set(LIB_LIB
    tao
    pthread
    ${YAMLCPP}    
    )

add_executable(test tests/test.cpp)
add_dependencies(test tao)
#force_redefine_file_macro_for_sources(test) #__FILE__
target_link_libraries(test ${LIB_LIB})

add_executable(test_config tests/test_config.cpp)
add_dependencies(test_config tao)
#force_redefine_file_macro_for_sources(test_config) #__FILE__
target_link_libraries(test_config ${LIB_LIB})

add_executable(test_thread tests/test_thread.cpp)
add_dependencies(test_thread tao)
#force_redefine_file_macro_for_sources(test_thread) #__FILE__
target_link_libraries(test_thread ${LIB_LIB})

add_executable(test_util tests/test_util.cpp)
add_dependencies(test_util tao)
#force_redefine_file_macro_for_sources(test_util) #__FILE__
target_link_libraries(test_util ${LIB_LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
