#include <iostream>

#include <SDL2/SDL.h>

#include <glad/glad.h>

#include "../sdl/PolySDL.h"

namespace PolyGL
{
    int initGL()
    {
        gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        glViewport(0, 0, PolySDL::WINDOW_WIDTH, PolySDL::WINDOW_HEIGHT);



        return 0;
    }
}