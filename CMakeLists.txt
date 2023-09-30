cmake_minimum_required(VERSION 3.7...3.27)

project(Neco-Arc-DVD-Logo
        VERSION 1.2
        DESCRIPTION "DVD Logo screensaver using SFML, but instead of the DVD Logo, we have Neco-Arc!"
        LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Neco-Arc-DVD-Logo src/main.cpp src/neco.cpp)
target_link_libraries(Neco-Arc-DVD-Logo PRIVATE sfml-graphics sfml-system sfml-window sfml-audio)
target_compile_features(Neco-Arc-DVD-Logo PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()