# Setting Up Dualie on CLion
Setting up devkitpro can be a bit tricky, especially when using
CMake and integrating it into an IDE. This guide will help set up 
devkitpro on a Clion environment.

# Prerequisites 
This is best done on a Linux environment. You can try to use Windows if you'd
like, but there are no guarantees that it will work. If you are using a Windows host,
you can easily setup devkitpro using WSL the same way you would set it up on a regular
Debian based host. You can follow instructions for [installing pacman](https://devkitpro.org/wiki/devkitPro_pacman) and 
[installing the 3ds toolchains](https://devkitpro.org/wiki/devkitPro_pacman#Using_Pacman).
Make sure to install `pkg-config` and `opusfile` using the following command:
`sudo dkp-pacman -S 3ds-opusfile 3ds-pkg-config`

# Setting up the toolchain
In CLion, navigate to **Settings => Build, Execution, Deployment => Toolchains**. 
Add a new toolchain and set it to **WSL**.  
* Set the CMake to WSL CMake
* Set the C compiler to `/opt/devkitpro/devkitARM/bin/arm-none-eabi-gcc`
* Set the C++ compiler to `/opt/devkitpro/devkitARM/bin/arm-none-eabi-g++`

Setting up the project CMake
If you have not already, clone Dualie into a directory of your choosing.
Navigate to **Settings => Build, Execution, Deployment => CMake**.
Set the toolchain to the WSL toolchain we created earlier. In CMake options,
add `-DCMAKE_TOOLCHAIN_FILE=/opt/devkitpro/cmake/3DS.cmake`. If you are using WSL or if
you get errors locating packages, scroll down to **Environment** and add the following:
`DEVKITPRO=/opt/devkitpro;DEVKITARM=/opt/devkitpro/devkitARM`.

# Building
In the toolbar, click **Tools => CMake => Reset Cache and Reload Project**.
Build the project by hitting the build button in your toolbar. 
You can then install the project by navigating to the build directory and running
`sudo make install`, which will install the library to your devkitpro directory.

# Conclusion
The toolchain will be saved forever, but you will need to add the cmake options 
and environment variables for all of the projects using devkitpro/Dualie. You should 
now be ready to start development with Dualie!