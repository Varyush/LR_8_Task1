cmake_minimum_required(VERSION 3.27)
project(Task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task1 main.cpp
        func.h
        input.cpp
        ouput.cpp
        add.cpp
        search.cpp
        delete.cpp
        sort.cpp
        edit.cpp
        menu.cpp)