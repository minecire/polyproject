#include <iostream>
#include <SDL2/SDL.h>

#include "../sdl/PolySDL.h"
#include "PolyGL.h"

namespace PolyGL
{

    unsigned int vertexBufferObject;

    unsigned int vertexArrayObject;

    int initGL()
    {
        gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glViewport(0, 0, PolySDL::WINDOW_WIDTH, PolySDL::WINDOW_HEIGHT);

        unsigned int vertexShader = loadShader("src/gl/Vertex.glsl", GL_VERTEX_SHADER);
        unsigned int fragmentShader = loadShader("src/gl/Fragment.glsl", GL_FRAGMENT_SHADER);
        unsigned int shaderProgram = createProgram(vertexShader, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glUseProgram(shaderProgram);


        return 0;
    }
}