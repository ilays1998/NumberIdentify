cmake_minimum_required(VERSION 3.20)
project(ex5_ilaysoffer C++)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex5_ilaysoffer
        Activation.cpp
        Activation.h
        Matrix.h
        Matrix.cpp
        Dense.cpp
        Dense.h
        MlpNetwork.cpp
        MlpNetwork.h
        my_test.cpp
        )