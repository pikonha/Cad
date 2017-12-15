#include <cstdlib>
#include "Point.h"

bool Point::operator==(const Point& p)
{
   return (std::abs(x - p.x) + std::abs(y - p.y)) == 0;
}

Point& Point::operator=(const Point& p)
{
   x= p.x;
   y= p.y;
   return *this;
}
