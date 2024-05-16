cmake_minimum_required(VERSION 3.26)
project(DiaryProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(DiaryProject
        main.cpp
        RecordManager.cpp
        FileHandler.cpp
        PasswordManager.cpp
        Menu.cpp
        main.h)
