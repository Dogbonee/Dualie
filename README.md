# Dualie

### What is it?
Dualie is a 3DS homebrew library heavily based on SFML that utilizes citro2d. It aims to provide an abstraction of citro2d.

### Limitations
Dualie is very early in development and currently only supports bare bones graphics programming. Contributions are welcome 
in any area. 

### Documentation
You can find the documentation for dualie [here](http://dogbonee.github.io/Dualie). Not many examples of the library currently exist,
however you can see a port of tetris that I made using the library [here](https://github.com/Dogbonee/3DS_Tetritime).

### How to build
DevkitPro is required to build this library. To build, set -DCMAKE_TOOLCHAIN_FILE to wherever 3DS.cmake lies in your filesystem,
then build the project normally using CMake.

### How to use
Use these lines to link audio:
```
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPUSFILE REQUIRED IMPORTED_TARGET opusfile)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE pkg-config opusfile)
target_link_libraries(${PROJECT_NAME} PkgConfig::OPUSFILE)
```

Use `target_link_libraries` to link `<path/to/libdualie.a>, citro2d, citro3d, ctru, m`

Use `target_include_directories` to the libraries include directory, then build with devkitPro
similar to the library build process. 

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

