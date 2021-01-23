#include "sdl/PolySDL.h"
#include "gl/PolyGL.h"

int main()
{
    //TODO: everything :twitchsmile:

/*
Structure of this project:
Main will start everything up:
    -getting gl running
    -getting sdl running
    -telling the engine to get running

Then these processes will work amongst themselves:
    -engine basically does everything, contains main loop and calls sdl and gl functions when it needs to
    -it will also call on other things that might need initialization like whatever will run projects, the game ui, etc.
*/
    //This part is easy, right?
    PolySDL::initSDL();
    PolyGL::initGL();
    //PolyEngine::initialize();

    PolySDL::endSDL();
    return 0;
}