#include "Bezier.h"


std::vector<Point> Bezier::getPoints()
{
	std::vector<Point> points;

	points.push_back(p1);

	for (float t = 0 ; t <= 1 ; t += 0.002f ) {
		float a = pow((1 - t), 2) * p1.x + (2 * t * (1 - t) * p3.x) + pow(t, 2)* p2.x;
		float b = pow((1 - t), 2) * p1.y + (2 * t * (1 - t) * p3.y) + pow(t, 2)* p2.y;

		points.push_back(Point(int(a), int(b)));
	}

	return points;
}