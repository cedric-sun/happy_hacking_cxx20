cmake_minimum_required(VERSION 3.16)
project(happy_hacking_c__20)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(5lex)

add_executable(env env.cc)