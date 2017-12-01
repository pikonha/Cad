#include "Bezier.h"


std::vector<Point> Bezier::getPoints()
{
	std::vector<Point> points;

	points.push_back(x);

	for (float t = 0; t <= 1; t += 0.0002) {
		float a = pow((1 - t), 2) * x.getX() + (2 * (1 - t) * t * y.getX()) + pow(t, 2)* z.getX();
		float b = pow((1 - t), 2) * x.getY() + (2 * (1 - t) * t * y.getY()) + pow(t, 2)* z.getY();

		points.push_back(Point(a, b));
	}

	return points;
}