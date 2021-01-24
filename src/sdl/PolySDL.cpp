#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "PolySDL.h"
namespace PolySDL
{
    int WINDOW_WIDTH = 1920;
    int WINDOW_HEIGHT = 1080;

    SDL_Window *window;
    SDL_GLContext SDLGLContext;


    void die(const char* msg)
    {
        printf("SDL %s, Error:%s\n", msg, SDL_GetError());
        endSDL();
        exit(1);
    }
    int initSDL()
    {

        if(SDL_Init(SDL_INIT_VIDEO) < 0)
            die("video init failed");

        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 6 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        window = SDL_CreateWindow("Poly Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if(!window)
            die("window creation failed");

        SDLGLContext = SDL_GL_CreateContext(window);

        SDL_Delay(2000); //delete this later once we actually have a loop set up
        return 0;
    }

    int endSDL()
    {
        SDL_GL_DeleteContext(SDLGLContext);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }
}