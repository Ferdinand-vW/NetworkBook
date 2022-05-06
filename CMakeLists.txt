cmake_minimum_required(VERSION 3.16)
project(NetworkBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(chapter2
        ch2.cpp)

add_executable(chapter3 ch3.cpp)

add_executable(chapter5 ch5.cpp)

add_executable(ch6_client ch6_client.cpp)

add_executable(ch6_server ch6_server.cpp)