#ifndef POINT_H
#define POINT_H

class point
{
public:
    point() = default;

    void dummy_method_in_cpp_file() const;

private:
    int _x{};
    int _y{};
};

#endif
