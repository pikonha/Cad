#include "Line.h"

std::vector<Point*> Line::getPoints()
{
	std::vector<Point*> points;

	points.push_back(x);
	points.push_back(y);

	return points;
}