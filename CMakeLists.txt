cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ipc 
        VERSION 1.0
        DESCRIPTION "A simple infix to postfix converter"
        LANGUAGE CXX_STANDARD
        )

add_subdirectory(src)