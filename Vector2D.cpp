/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * Vector2D.cpp
 */

#include <iostream>
#include "Vector2D.h"

Vector2D::Vector2D()
{
    _x = 0.0f;
    _y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
    _x = x;
    _y = y;
}

Vector2D& Vector2D::add(const Vector2D& v)
{
    _x += v._x;
    _y += v._y;

    return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& v)
{
    _x -= v._x;
    _y -= v._y;

    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& v)
{
    _x *= v._x;
    _y *= v._y;

    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& v)
{
    _x /= v._x;
    _y /= v._y;

    return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
    return v1.add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
    return v1.subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
    return v1.multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
    return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    return add(v);
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    return subtract(v);
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
    return multiply(v);
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
    return divide(v);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
    stream << "Vector2D(" << v._x << "," << v._y << ")";

    return stream;
}

