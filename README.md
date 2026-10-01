# OppnGL

A learning project for modern OpenGL in C++, built with CMake . It's my sandbox for working through the graphics pipeline and understanding what each layer (textures, shaders, blending, uniforms) means and how it connects.

## Tech

- **Language:** C++20
- **Windowing / input:** [GLFW](https://www.glfw.org/)
- **Function loading:** [GLEW](https://glew.sourceforge.net/) (static)
- **Build:** CMake (4.0+) with Ninja

## Project layout

```
OppnGL/
├── Dependencies/      # Prebuilt GLFW + GLEW (headers and libs)
├── include/           # Project headers
├── res/               # Shaders, textures, other runtime resources
├── src/               # Source files 
│   ├── vendor/        # Third-party single-file/source libs(glm/imgui)
│   └── tests/         # Tests for small features
├── CMakeLists.txt
└── CMakePresets.json
```

The executable ends up in `bin/<Debug|Release>/OppnGL.exe`.

It is basically a decent template with few abstractions and a decent test framework 
