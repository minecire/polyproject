#ifndef POLY_GL
#define POLY_GL

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

unsigned int loadShader(const char* filepath, GLenum type);
unsigned int createProgram(unsigned int vertex, unsigned int fragment);

namespace PolyGL
{
    int initGL();
    void updateBuffers();
}

#endif