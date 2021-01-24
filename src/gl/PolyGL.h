#ifndef POLY_GL
#define POLY_GL

#include <glad/glad.h>

unsigned int loadShader(const char* filepath, GLenum type);
unsigned int createProgram(unsigned int vertex, unsigned int fragment);

namespace PolyGL
{
    int initGL();
}

#endif