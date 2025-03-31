cmake_minimum_required(VERSION 3.28)
project(boids LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


# Set source files
set(SOURCES
    src/main.cpp
    src/core/tunableparams.cpp
    src/core/bird.cpp
    src/core/flock.cpp
    src/core/slider.cpp
    src/core/ui.cpp
)

# Set headers files
set(HEADERS
    src/include/constants.h
    src/include/bird.h
    src/include/flock.h
    src/include/slider.h
    src/include/tunableparams.h
    src/include/ui.h
)

add_executable(main ${SOURCES} ${HEADERS})
target_compile_features(main PRIVATE cxx_std_17)
target_include_directories(main PRIVATE src/) 
target_link_libraries(main PRIVATE SFML::Graphics)
