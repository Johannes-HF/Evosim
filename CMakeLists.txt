cmake_minimum_required(VERSION 3.10)

project(evosim C CXX)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON )

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(evosim 
	src/main.cpp
	src/glad.c
	src/matte.cpp
	src/GLfunksjoner.cpp
)

# OpenGL og GLAD pakker:
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_compile_options(evosim PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(evosim PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/shaders" 
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
