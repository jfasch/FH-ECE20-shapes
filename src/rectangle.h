#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class rectangle
{
public:
    rectangle() = default;

private:
    point _bottom_left{};
    point _top_right{};
};

#endif
