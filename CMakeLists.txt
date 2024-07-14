cmake_minimum_required(VERSION 3.3.0)
project(opengl-tutorial VERSION 0.1.0)

link_directories(dependencies/library)

include_directories(dependencies/include/glad)
include_directories(dependencies/include/KHR)
include_directories(dependencies/include/GLFW)
include_directories(dependencies/include)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(opengl-tutorial ${SOURCES})

find_package(OpenGL REQUIRED)
target_link_libraries(opengl-tutorial PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(opengl-tutorial PRIVATE glfw3)

#file(COPY Shaders DESTINATION /)