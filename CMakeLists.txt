cmake_minimum_required(VERSION 3.20)

project(TicTacToeSFML LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.2
    GIT_SHALLOW    ON
    EXCLUDE_FROM_ALL
    SYSTEM
)

# Only build what we actually need
set(SFML_BUILD_AUDIO   OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SFML)

add_executable(tictactoe
    src/main.cpp
    src/Board.cpp
    src/Game.cpp
)

target_compile_features(tictactoe PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(tictactoe PRIVATE /W4)
else()
    target_compile_options(tictactoe PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_link_libraries(tictactoe PRIVATE SFML::Graphics)

# Copy assets next to the binary after each build
add_custom_command(TARGET tictactoe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:tictactoe>/assets
)
