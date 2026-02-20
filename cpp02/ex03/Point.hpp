#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
    const Fixed x;
    const Fixed y;
    public:
    Point();
    Point(const float one, const float two);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();
    float get_x(void)const;
    float get_y(void)const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif