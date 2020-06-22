/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * Game.cpp
 */

#include "Game.h"
#include "Components.h"
#include "Vector2D.h"

// Event structure.
SDL_Event Game::_event;

// Default renderer.
SDL_Renderer* Game::_renderer = nullptr;

ECS_Manager ecsManager;

auto& player(ecsManager.addEntity());

/**
 * Default constructor.
 */
Game::Game()
{

}

/**
 * Default destructor.
 */
Game::~Game()
{

}

/**
 * Init Game.
 *
 * @param const char* Window title.
 * @param int Window X position.
 * @param int Window Y position.
 * @param int Window width.
 * @param int Window height.
 * @param bool Window full screen mode.
 * @return void

 */
void Game::init(const char* title, int x, int y, int w, int h, bool fullScreen = false)
{
    // Init SDL with selected flags.
    if(SDL_Init(SDL_INIT_FLAGS) == 0) {
        // Extend window flags.
        int windowFlags = SDL_WINDOW_FLAGS;

        if(fullScreen == true) {
            windowFlags |= SDL_WINDOW_FULLSCREEN;
        }

        // Init game main window.
        _window = SDL_CreateWindow(title, x, y, w, h, windowFlags);

        if(_window == NULL) {
            SDL_LogError(0, "Error Creating Window... %s",
                SDL_GetError()
            );
        } else {
            // Init renderer.
            _renderer = SDL_CreateRenderer(_window, -1, 0);

            if(_renderer == NULL) {
                SDL_LogError(0, "Error Creating Renderer... %s",
                    SDL_GetError()
                );
            } else {
                SDL_SetRenderDrawColor(_renderer, 0, 0xff, 0, 0xff);

                _isRunning = true;
            }
        }
    } else {
        SDL_LogError(0, "Error Initializing SDL... %s",
            SDL_GetError()
        );
    }

    player.addComponent<TransformComponent>(50.0f, 50.0f);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<KeyboardController>();
}

/**
 * Handle events.
 *
 * @return void
 */
void Game::handleEvents(void)
{
    SDL_PollEvent(&_event);

    switch(_event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
        default:
            break;
    }
}

/**
 * Update.
 *
 * @return void
 */
void Game::update(void)
{
    ecsManager.gc();
    ecsManager.update();
}

/**
 * Render.
 *
 * @return void
 */
void Game::render(void)
{
    SDL_RenderClear(_renderer);

    ecsManager.draw();

    SDL_RenderPresent(_renderer);
}

/**
 * Clean up.
 *
 * @return void
 */
void Game::clean(void)
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

