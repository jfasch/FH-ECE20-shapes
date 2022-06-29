#include "point.h"

point& point::operator+=(point other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

point point::operator+(point other) const
{
    int x = _x + other._x;
    int y = _y + other._y;
    return point{x,y};
}

std::ostream& operator<<(std::ostream& s, point r)
{
    s << '(' << r.x() << ',' << r.y() << ')';
    return s;
}
