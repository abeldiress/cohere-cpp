cmake_minimum_required(VERSION 3.10)

project(cohere-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CURL REQUIRED)

include_directories(lib lib/nlohmann)

add_executable(main main.cpp 
src/curlsession.cpp 
src/interface.cpp
src/chat.cpp
# src/apikey.cpp 
# src/classify.cpp 
# src/curlsession.cpp 
# src/connectors.cpp 
# src/dataset.cpp 
# src/embed.cpp 
# src/finetune.cpp  
# src/models.cpp 
# src/rerank.cpp 
# src/tokens.cpp
# lib/interface.h
)

target_link_libraries(main CURL::libcurl)
