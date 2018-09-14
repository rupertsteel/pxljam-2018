
cmake_minimum_required(VERSION 3.10)

project(pxljam C)

add_executable(game main.c assetsGenerated/wink.c)

add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/game.rel
            ${CMAKE_BINARY_DIR}/game.gbc)
