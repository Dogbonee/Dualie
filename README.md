# Dualie

### What is it?
Dualie is a 3DS homebrew library heavily based on SFML that utilizes citro2d. It aims to provide an abstraction of citro2d.

### Limitations
Dualie is very early in development and currently only supports bare bones graphics programming. Contributions are welcome 
in any area. 

### Documentation
You can find the documentation for dualie [here](http://dogbonee.github.io/Dualie). Not many examples of the library currently exist,
however you can see a port of tetris that made using the library [here](https://github.com/Dogbonee/3DS_Tetritime).

### How to build
DevkitPro is required to build this library. Dualie also depends on libopusfile and pkg-config, which can be installed through devkitPro's pacman package manager like so: 
`pacman -S 3ds-opusfile 3ds-pkg-config` To build, set -DCMAKE_TOOLCHAIN_FILE to wherever 3DS.cmake lies in your filesystem,
then build the project normally using CMake. You can install the library by using `make install` or `ninja install`. Note that
the `DEVKITPRO` environment variable needs to be correctly set.

### How to use
Similar to building, libopusfile and pkg-config must be installed, and `CMAKE_TOOLCHAIN_FILE` must be set to the 3ds.cmake file. `Dualie_DIR` then needs to be set to the cmake directory 
located in the dualie root directory. If the config file cannot be found, set `CMAKE_PREFIX_PATH` to the Dualie_DIR variable like so: 
`set(CMAKE_PREFIX_PATH ${Dualie_DIR}` Then one can link to the library normally: `target_link_libraries(${PROJECT_NAME} ${DUALIE_LIBRARY})`  

Below is a sample CMakeLists.txt that fully links the library and its dependencies:

```
cmake_minimum_required(VERSION 3.28)
project(Dualie_Demo)
set(CMAKE_CXX_STANDARD 17)
set(Dualie_DIR "<DualieRoot>/cmake")
set(CMAKE_PREFIX_PATH ${Dualie_DIR}
find_package(Dualie REQUIRED)
add_executable(Dualie_Demo main.cpp)
target_link_libraries(${PROJECT_NAME} ${DUALIE_LIBRARY})
target_compile_options(${PROJECT_NAME} PRIVATE
        -g -O2 -Wall
)
ctr_generate_smdh(${PROJECT_NAME}.smdh
        NAME "${PROJECT_NAME}"
        DESCRIPTION "v1.0.0"
        AUTHOR "SOMEBODY"
)
ctr_create_3dsx(${PROJECT_NAME}
        SMDH ${PROJECT_NAME}.smdh
)
```

## Example

Similarly to SFML, graphics revolve around a RenderWindow object, and draw targets can be selected in the clear function.
Below is a simple program that draws a rectangle to the top screen and a circle to the bottom screen. 

```
#include <Dualie/Dualie.hpp>

int main()
{
    const int TOP_WIDTH = 400;
    const int TOP_HEIGHT = 240;

    const int BOTTOM_WIDTH = 320;
    const int BOTTOM_HEIGHT = 240;

    dl::RenderWindow window;

    dl::RectangleShape rect;
    rect.setSize(dl::Vector2f(150,150));
    rect.setFillColor(dl::Color::Red);
    rect.setOrigin(dl::Vector2f(75,75));
    rect.setPosition(TOP_WIDTH/2, TOP_HEIGHT/2);

    dl::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(dl::Color::Blue);
    circle.setOrigin(50,50);
    circle.setPosition(BOTTOM_WIDTH/2, BOTTOM_HEIGHT/2);

    while(window.isOpen()){

        window.clear(dl::TOP_SCREEN, dl::Color(200,200,200));
        window.draw(rect);
        window.display();

        window.clear(dl::BOTTOM_SCREEN, dl::Color(50,0,0));
        window.draw(circle);
        window.display();

    }

    return 0;
}
```

