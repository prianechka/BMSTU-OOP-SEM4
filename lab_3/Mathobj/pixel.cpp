#include "pixel.h"

Pixel::Pixel(int _x, int _y)
{
    x = _x;
    y = _y;
}

int Pixel::get_x() const
{
    return x;
}

int Pixel::get_y() const
{
    return y;
}

void Pixel::set_x(int _x)
{
    x = _x;
}

void Pixel::set_y(int _y)
{
    y = _y;
}
