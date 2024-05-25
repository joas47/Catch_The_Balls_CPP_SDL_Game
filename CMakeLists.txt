cmake_minimum_required(VERSION 3.25)
project(CatchTheBalls)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
message("SDL2 include path: ${SDL2_INCLUDE_DIRS}")
find_package(SDL2_ttf REQUIRED)
message("SDL2_ttf include path: ${SDL2_TTF_INCLUDE_DIRS}")
find_package(SDL2_image REQUIRED)
message("SDL2_image include path: ${SDL2_IMAGE_INCLUDE_DIRS}")
find_package(SDL2_mixer REQUIRED)
message("SDL2_mixer include path: ${SDL2_MIXER_INCLUDE_DIRS}")

include_directories(include resources src)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_MIXER_LIB_DIR})
add_executable(CatchTheBalls src/main.cpp src/System.cpp include/System.h src/Component.cpp include/Component.h include/Label.h src/Label.cpp include/Button.h src/Button.cpp
        src/FallingObject.cpp
        include/FallingObject.h
        include/Player.h
        src/Player.cpp
        include/Game.h
        include/CatchTheBallsGame.h
        include/GameEngine.h
        src/GameEngine.cpp
        src/CatchTheBallsGame.cpp
        src/Game.cpp)
target_link_libraries(CatchTheBalls ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} SDL2_ttf SDL2_image SDL2_mixer)