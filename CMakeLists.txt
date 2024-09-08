cmake_minimum_required(VERSION 3.10)

project(cohere-cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(lib lib/nlohmann)

add_executable(cohere-cpp main.cpp src/curlsession.cpp)

find_package(CURL REQUIRED)

target_link_libraries(cohere-cpp CURL::libcurl)
