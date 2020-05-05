cmake_minimum_required(VERSION 3.0)
project(Simulator VERSION 1.0.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)

file(GLOB VIEW_H "src/view/*.hpp")
file(GLOB VIEW_C "src/view/*.cpp")

file(GLOB MODEL_H "src/model/*.hpp")
file(GLOB MODEL_C "src/model/*.cpp")

add_library(
  model
  ${MODEL_H}
  ${MODEL_C}
)

add_library(
  view
  ${VIEW_H}
  ${VIEW_C}
)

target_include_directories(view PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(sim src/main.cpp)

target_link_libraries(sim PUBLIC ${SDL2_LIBRARIES} -lSDL2_image)
target_link_libraries(sim PRIVATE model)
target_link_libraries(sim PRIVATE view)
