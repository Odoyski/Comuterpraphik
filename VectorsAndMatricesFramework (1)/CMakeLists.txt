# Define the minimum CMAKE version required:
cmake_minimum_required(VERSION 3.0)

# Define the project:
project(VectorsAndMatrices CXX)

# Set C++ stardard:
set(CMAKE_CXX_STANDARD 11)

# Enable automatic include of generated files (like paths.h):
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include IMGUI (which already includes GLFW):
add_subdirectory(lib/imgui-1.88)

# Include GLAD for OpenGL 3.3 Core functionalities:
add_subdirectory(lib/glad)


# Define all header files we want to compile:
set(HEADERS 
    src/test_gui.h
    src/math/Vec4f.h
    src/math/Mat4f.h
)

# Define all source files we want to compile:
set(SOURCES 
    src/main.cpp
    src/math/Vec4f.cpp
    src/math/Mat4f.cpp
)

# Define shader & resources which should be listed in IDE:
set(RESOURCES
)

# Define executables with source files and resources:
add_executable(VectorsAndMatrices ${SOURCES} ${HEADERS} ${RESOURCES})

# IMGUI specific compile definition:
target_compile_definitions(VectorsAndMatrices PUBLIC -DCMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# Define the libraries to link against:
target_link_libraries(VectorsAndMatrices PUBLIC imgui glad)

