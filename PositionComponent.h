/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * SpriteComponent.h
 */

#pragma once

#include "Components.h"

class PositionComponent : public Component
{
private:
    int _x;
    int _y;
public:
    PositionComponent()
    {
        _x = 0;
        _y = 0;
    }

    PositionComponent(int x, int y)
    {
        _x = x;
        _y = y;
    }

    int x() const { return _x; }
    int y() const { return _y; }

    void update() override
    {
        _x++;
        _y++;
    }

    void pos(int x, int y) {
        _x = x;
        _y = y;
    }
};
