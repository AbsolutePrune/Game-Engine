cmake_minimum_required(VERSION 3.0)
project(MYENGINE)


include_directories(
    src
)

add_library(myengine
    src/myengine/Core.cpp

    src/myengine/myengine.h
    src/myengine/Core.h
)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)