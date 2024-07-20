# Dualie

### What is it?
Dualie is a 3DS homebrew library heavily based on SFML that utilizes citro2d. It aims to provide an abstraction of citro2d.

### Limitations
Dualie is very early in development and currently only supports bare bones graphics programming. Contributions are welcome 
in any area. 

### Documentation
Dualie lacks documentation, but aims to be fairly intutive and similar to SFML. As always, contributions in this department
are more than welcome.

### How to build
DevkitPro is required to build this library. To build, set -DCMAKE_TOOLCHAIN_FILE to wherever 3DS.cmake lies in your filesystem,
then build the project normally using CMake.

### How to use
Use `target_link_libraries` to link <path/to/libdualie.a>, citro2d, citro3d, ctru, m  
Use `target_include_directories` to the libraries include directory, then build with devkitPro
similar to the library build process. 