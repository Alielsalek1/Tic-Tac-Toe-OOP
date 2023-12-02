cmake_minimum_required(VERSION 3.5)
project(tic_tac_OOP)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(tic_tac_OOP main.cpp
        pyramid_board.cpp
        RandomPlayer.cpp
        X_O_Board.cpp
        X_O_App.cpp
        GameManager.cpp
        Player.cpp
        pyramid_board.h)
