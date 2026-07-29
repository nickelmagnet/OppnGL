cmake_minimum_required(VERSION 4.0)
project(OppnGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_executable(OppnGL
	src/main.cpp

)

target_include_directories(OppnGL PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/include"

)

target_link_directories(OppnGL PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/lib-vc2022"
	"${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW/lib/Release/x64"
)

target_link_libraries(OppnGL PRIVATE 
    glfw3
	opengl32
	glew32s
)

target_compile_definitions(OppnGL PRIVATE GLEW_STATIC)
