cmake_minimum_required(VERSION 3.0)
project(MYENGINE)


include_directories(
    src
    contrib/windows-cl-amd64/include
)

link_directories(
 ${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(rend
 src/rend/Animation.cpp
 src/rend/Buffer.cpp
 src/rend/Mesh.cpp
 src/rend/Model.cpp
 src/rend/ModelRenderer.cpp
 src/rend/RenderTexture.cpp
 src/rend/Renderer.cpp
 src/rend/Shader.cpp
 src/rend/Texture.cpp
 src/rend/rendmath.cpp
)

target_link_libraries(rend glew32 opengl32)

add_library(myengine
    src/myengine/Core.cpp
    src/myengine/Core.h

    src/myengine/myengine.h
 
    src/myengine/Entity.cpp
    src/myengine/Entity.h

    src/myengine/Component.cpp
    src/myengine/Component.h

    src/myengine/TriangleRenderer.cpp
    src/myengine/TriangleRenderer.h
)

target_link_libraries(myengine SDL2 SDL2main rend)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)