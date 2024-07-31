find_path(DUALIE_INCLUDE_DIRS
    NAMES Dualie.hpp
    PATHS ${DEVKITPRO}/portlibs/3ds/include/Dualie
)

find_library(DUALIE_LIBRARY
    NAMES dualie
    PATHS PATHS ${DEVKITPRO}/portlibs/3ds/lib
)

set(DUALIE_FOUND ${DUALIE_LIBRARY})
if(DUALIE_FOUND)
    set(DUALIE_INCLUDE_DIRS ${DUALIE_INCLUDE_DIRS})
endif()