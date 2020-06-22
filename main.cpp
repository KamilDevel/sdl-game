/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * main.cpp
 */

#include "main.h"
#include "Game.h"

Game* game = nullptr;

/**
 * Main program
 */
int main(void)
{
    // -- FPS
    const int fps = 60;
    const int frameDelay = 1000 / fps;
    Uint32 frameStart;
    int frameTime;
    // -- FPS

    game = new Game;

    game->init("SDL-Game v1.0 pre-alpha", 0, 0, 1024, 768, false);

    while(game->isRunning()) {
        // -- FPS
        frameStart = SDL_GetTicks();
        // -- FPS

        game->handleEvents();
        game->update();
        game->render();

        // -- FPS
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
        // -- FPS
    }

    game->clean();

    return 0;
}
