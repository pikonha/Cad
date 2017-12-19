#include "Line.h"

std::vector<Point> Line::getPoints()
{
	std::vector<Point> points;

	points.push_back(p1);
	points.push_back(p2);

	return points;
}