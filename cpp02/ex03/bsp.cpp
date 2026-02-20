#include "Point.hpp"
float area(Point const a, Point const b, Point const c)
{
    float ar;
    ar=(a.get_x()*(b.get_y()-c.get_y())+b.get_x()*(c.get_y()-a.get_y())+c.get_x()*(a.get_y()-b.get_y()))/2;
    if (ar<0)
        return(-1*ar);
    return(ar);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float abc=area(a,b,c);
    float abp=area(a,b,point);
    float apc=area(a,point,c);
    float pbc=area(point,b,c);
    if (abp <= 0 || apc<=0 || pbc<=0 || abc<= 0)
        return (false);
    return(abc==abp+apc+pbc);

}
