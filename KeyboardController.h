/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * KeyboardController.h
 */

#pragma once

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
    TransformComponent* _transform;

    void init() override
    {
        _transform = &_entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        // Key pressed.
        if(Game::_event.type == SDL_KEYDOWN) {
            switch(Game::_event.key.keysym.sym) {
                case SDLK_w:
                    _transform->_velocity._y = -1;
                    break;
                case SDLK_a:
                    _transform->_velocity._x = -1;
                    break;
                case SDLK_d:
                    _transform->_velocity._x = 1;
                    break;
                case SDLK_s:
                    _transform->_velocity._y = 1;
                    break;
                default:
                    break;
            }
        }

        // Key released.
        if(Game::_event.type == SDL_KEYUP) {
            switch(Game::_event.key.keysym.sym) {
                case SDLK_w:
                    _transform->_velocity._y = 0;
                    break;
                case SDLK_a:
                    _transform->_velocity._x = 0;
                    break;
                case SDLK_d:
                    _transform->_velocity._x = 0;
                    break;
                case SDLK_s:
                    _transform->_velocity._y = 0;
                    break;
                default:
                    break;
            }
        }
    }
};
