/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * Game.h
 */

#pragma once

// These are the flags which will be passed to SDL_Init().
#define SDL_INIT_FLAGS SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS

// Window flags.
#define SDL_WINDOW_FLAGS SDL_WINDOW_SHOWN

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
private:
    // Game running flag.
    bool _isRunning = false;

    // Game main window.
    SDL_Window* _window;
public:
    // Event structure.
    static SDL_Event _event;

    // Default renderer.
    static SDL_Renderer* _renderer;

    /**
     * Default constructor.
     */
    Game();

    /**
     * Default destructor.
     */
    ~Game();

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
    void init(const char*, int, int, int, int, bool);

    /**
     * Handle events.
     *
     * @return void
     */
    void handleEvents(void);

    /**
     * Update.
     *
     * @return void
     */
    void update(void);

    /**
     * Render.
     *
     * @return void
     */
    void render(void);

    /**
     * Clean up.
     *
     * @return void
     */
    void clean(void);

    /**
     * Clear.
     *
     * @return void
     */
    bool isRunning(void) const
    {
        return _isRunning;
    }
};
