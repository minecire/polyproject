#ifndef POLY_SDL
#define POLY_SDL

namespace PolySDL
{
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;


    int initSDL();
    int endSDL();

    void swapWindow();
    void processEvents();
}

#endif