cmake_minimum_required(VERSION 3.22)
project(editor C)

set(CMAKE_C_STANDARD 99)

add_executable(editor main.c line.editor.c line.editor.h)
