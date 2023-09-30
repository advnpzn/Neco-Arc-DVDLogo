cmake_minimum_required(VERSION 3.7...3.27)

project(Neco-Arc-DVD-Logo
        VERSION 1.2
        DESCRIPTION "DVD Logo screensaver using SFML, but instead of the DVD Logo, we have Neco-Arc!"
        LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Neco-Arc-DVD-Logo src/main.cpp src/neco.cpp)
target_link_libraries(Neco-Arc-DVD-Logo PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)