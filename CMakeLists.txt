cmake_minimum_required(VERSION 3.21)

project(1486_thread_future_async)

set(CMAKE_CXX_STANDARD 11)

add_executable(1486_thread_future_async main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(1486_thread_future_async PRIVATE Threads::Threads)