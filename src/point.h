#ifndef POINT_H
#define POINT_H

#include <ostream>

class point
{
public:
    point() = default;
    point(int x, int y) : _x{x}, _y{y} {}

    bool operator==(point other) const { return _x==other._x && _y==other._y; }
    bool operator!=(point other) const { return !operator==(other); }
    point& operator+=(point other);
    point operator+(point other) const;
    point operator-() const { return point{-_x,-_y}; }

    int x() const { return _x; }
    int y() const { return _y; }

private:
    int _x{0};
    int _y{0};
};

std::ostream& operator<<(std::ostream& s, point r);

#endif
