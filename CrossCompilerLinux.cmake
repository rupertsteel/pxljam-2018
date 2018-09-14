
set(CMAKE_SYSTEM_NAME gbc)
set(CMAKE_SYSTEM_PROCESSOR lr2)

set(gbdkDir /opt/gbdk/bin)
find_program(gbdkLcc lcc PATHS ${gbdkDir})
set(CMAKE_C_COMPILER ${gbdkLcc})
set(CMAKE_AR ${gbdkLcc} CACHE FILEPATH "Archiver")
SET(CMAKE_EXE_LINKER_FLAGS "-Wl-yp0x143=0x80")
SET(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> -o <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_C_COMPILER_WORKS 1)
