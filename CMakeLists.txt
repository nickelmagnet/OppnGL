cmake_minimum_required(VERSION 4.0)
project(OppnGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(OppnGL
	src/main.cpp

)

target_include_directories(OppnGL PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include"


)

target_link_directories(OppnGL PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/lib-vc2022"
)

target_link_libraries(OppnGL PRIVATE 
    glfw3
    winmm
    gdi32
    opengl32
    user32
    shell32
)
