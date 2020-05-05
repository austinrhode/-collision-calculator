cmake_minimum_required(VERSION 3.0)
project(Simulator VERSION 1.0.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)

add_executable(SDLdemo demo.cpp)

target_link_libraries(SDLdemo PUBLIC ${SDL2_LIBRARIES} -lSDL2_image)
