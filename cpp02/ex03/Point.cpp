#include "Point.hpp"

Point ::Point():x(0),y(0){

}
Point::Point(const float one, const float two):x(one), y(two)
{
}
Point::Point(const Point &other):x(other.x),y(other.y)
{
    
}
Point& Point::operator=(const Point& other)
{
    if(this==&other)
        return(*this);
    return(*this);       
}
Point::~Point(){}

float Point::get_x(void)const
{
    return(x.toFloat());
}
float Point::get_y(void)const
{
    return(y.toFloat());
}