cmake_minimum_required(VERSION 3.16)
project(happy_hacking_c__20)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(0tmp)
add_subdirectory(5lex)
add_subdirectory(6basics)
add_subdirectory(25algorithm)


add_executable(env env.cc)