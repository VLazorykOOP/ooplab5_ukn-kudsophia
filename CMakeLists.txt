cmake_minimum_required(VERSION 3.24)
project(ooplab5_ukn_kudsophia)

set(CMAKE_CXX_STANDARD 14)

include_directories(OOPLab5T)

add_executable(
        ooplab5_ukn_kudsophia

        OOPLab5T/lab5_2/5_2.cpp
        OOPLab5T/lab5.1/5_1.cpp
        OOPLab5T/lab5_3.cpp)
