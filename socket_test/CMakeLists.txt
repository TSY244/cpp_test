cmake_minimum_required(VERSION 3.10.2)
project(socket_test)

set(CMAKE_CXX_STANDARD 11)

add_executable(socket_test main.cpp socket/socket.hpp socket/socket.cpp )

add_executable(Client Client.cpp socket/socket.hpp socket/socket.cpp)

target_link_libraries(socket_test  pthread)
target_link_libraries(Client  pthread)
