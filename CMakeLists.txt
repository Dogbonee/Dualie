cmake_minimum_required(VERSION 3.2)
project(dualie)



add_library(dualie STATIC
        include/Dualie/Graphics.hpp
        src/Dualie/Graphics/RenderWindow.cpp
        include/Dualie/Graphics/RenderWindow.hpp
        src/Dualie/System/Input.cpp
        include/Dualie/System/Input.hpp
        src/Dualie/Graphics/Color.cpp
        include/Dualie/Graphics/Color.hpp
        include/Dualie/Graphics/Drawable.hpp
        src/Dualie/Graphics/Transformable.cpp
        include/Dualie/Graphics/Transformable.hpp
        include/Dualie/System/Vector2.hpp
        src/Dualie/Graphics/CircleShape.cpp
        include/Dualie/Graphics/CircleShape.hpp
        src/Dualie/Graphics/Shape.cpp
        include/Dualie/Graphics/Shape.hpp
        include/Dualie/Graphics/RectangleShape.hpp
        src/Dualie/Graphics/RectangleShape.cpp
        include/Dualie/System/Rect.hpp
        include/Dualie/Dualie.hpp
        include/Dualie/Graphics/View.hpp
        src/Dualie/Graphics/View.cpp
        src/Dualie/Graphics/Text.cpp
        include/Dualie/Graphics/Text.hpp
        src/Dualie/Graphics/TextBuffer.cpp
        include/Dualie/Graphics/TextBuffer.hpp
        src/Dualie/Audio/Music.cpp
        include/Dualie/Audio/Music.hpp
        include/Dualie/Audio.hpp
        src/Dualie/Graphics/Sprite.cpp
        include/Dualie/Graphics/Sprite.hpp
        src/Dualie/Graphics/SpriteSheet.cpp
        include/Dualie/Graphics/SpriteSheet.hpp
        src/Dualie/Graphics/Drawable.cpp
        src/Dualie/System/Clock.cpp
        include/Dualie/System/Clock.hpp
        src/Dualie/System/Time.cpp
        include/Dualie/System/Time.hpp
        include/Dualie/System.hpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPUSFILE REQUIRED IMPORTED_TARGET opusfile)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE pkg-config opusfile)
target_link_libraries(${PROJECT_NAME} citro2d citro3d ctru m)
target_link_libraries(${PROJECT_NAME} PkgConfig::OPUSFILE)

target_compile_options(${PROJECT_NAME} PRIVATE
        -g -O2 -Wall
)


install(TARGETS dualie DESTINATION ${DEVKITPRO}/portlibs/3ds/lib)
install(DIRECTORY include/Dualie DESTINATION ${DEVKITPRO}/portlibs/3ds/include)