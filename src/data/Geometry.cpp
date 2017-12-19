#include "Geometry.h"

bool Geometry::operator==(const Geometry& i)
{
   return (p1 == i.p1) && (p2 == i.p2);
}
