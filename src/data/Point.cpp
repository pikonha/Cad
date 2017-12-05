#include "Point.h"

bool Point::operator==(Point * p)
{
	if (x == p->getX() && y == p->getY())
		return true;

	return false;
}
