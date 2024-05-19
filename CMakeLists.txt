cmake_minimum_required(VERSION 3.26)
project(lab4Buntsev)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4Buntsev main.cpp
        menu.h
        set.h
        binaryTree.h
        binaryHeap.h
        structures.h
        tests.cpp
        func.h)
