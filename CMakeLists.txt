cmake_minimum_required(VERSION 3.20)
project(Cinema)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cinema main.cpp tickets.h manager.cpp manager.h Customer.cpp Customer.h Mainwindow.cpp Mainwindow.h)
