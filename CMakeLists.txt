cmake_minimum_required(VERSION 3.23)
project(final)

set(CMAKE_CXX_STANDARD 14)

add_executable(final main.cpp Application.cpp Application.h Board.cpp Board.h AnimatedSprite.cpp AnimatedSprite.h ColorSquare.cpp ColorSquare.h Moles.cpp Moles.h Score.cpp Score.h)

target_link_libraries(final sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)