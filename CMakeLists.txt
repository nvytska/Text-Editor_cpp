cmake_minimum_required(VERSION 3.16)
project(TextEditorCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextEditorCpp
        main.cpp
        textStorage.cpp
        Editor.cpp
        fileLogic.cpp
)
