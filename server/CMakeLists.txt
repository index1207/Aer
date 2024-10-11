cmake_minimum_required(VERSION 3.20)
project(bomber_server)

set(CMAKE_CXX_STANDARD 20)

find_package(netcpp CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)

add_subdirectory(src)
