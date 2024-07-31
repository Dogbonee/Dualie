#This script finds and includes the libraries necessary to link dualie to the project.
#One can link to dualie by calling target_link_libraries(${PROJECT_NAME} ${DUALIE_LIBRARY})
find_path(DUALIE_INCLUDE_DIRS
    NAMES Dualie.hpp
    PATHS ${DEVKITPRO}/portlibs/3ds/include/
)

find_library(DUALIE_LIBRARY
    NAMES dualie
    PATHS PATHS ${DEVKITPRO}/portlibs/3ds/lib
)
set(PATH_FOUND ${DUALIE_INCLUDE_DIRS})
if(PATH_FOUND)
    string(REGEX REPLACE "/[^/]*$" "" DUALIE_INCLUDE_DIRS "${DUALIE_INCLUDE_DIRS}")
endif()

set(DUALIE_FOUND ${DUALIE_LIBRARY})
if(DUALIE_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(OPUSFILE REQUIRED IMPORTED_TARGET opusfile)
    include_directories(${DUALIE_INCLUDE_DIRS} pkg-config opusfile)
    set(DUALIE_LIBRARY ${DUALIE_LIBRARY} citro2d citro3d ctru m PkgConfig::OPUSFILE)
endif()
