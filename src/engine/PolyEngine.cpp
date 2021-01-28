#include <iostream>
#include "../Main.h"
#include "../sdl/PolySDL.h"
#include "../gl/PolyGL.h"
#include "PolyEngine.h"

namespace PolyEngine
{
    bool exit = false;
    
    void processKeyPress(SDL_KeyboardEvent e)
    {
        std::cout << "hi!";
        switch(e.keysym.sym)
        {
            case SDLK_DELETE:
                PolyEngine::exit = true;
                break;
        }
    }

    void processEvents()
    {
        SDL_Event e;
        while(SDL_PollEvent(&e) != 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    exit = true;
                    break;
                case SDL_KEYDOWN:
                    processKeyPress(e.key);
                    break;
            }
        }
    }

    void beginLoop()
    {
        while(!exit)
        {
            //draw3D();
            //drawUI();
            
            PolyGL::updateBuffers();
            processEvents();
        }
    }

    int initEngine()
    {
        //let's make a game engine!! :D

        beginLoop();

        return 0;
    }
}