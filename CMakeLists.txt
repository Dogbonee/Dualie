cmake_minimum_required(VERSION 3.28)
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
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} citro2d citro3d ctru m)

target_compile_options(${PROJECT_NAME} PRIVATE
        -g -O2 -Wall
)
