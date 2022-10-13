cmake_minimum_required(VERSION 3.0)
project(MYENGINE)


include_directories(
    src
)

add_library(myengine
    src/myengine/Core.cpp
    src/myengine/Core.h

    src/myengine/myengine.h
 
    src/myengine/Entity.cpp
    src/myengine/Entity.h

    src/myengine/Component.cpp
    src/myengine/Component.h
)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)