#include "Bezier.h"


std::vector<Point*> Bezier::getPoints()
{
	std::vector<Point*> points;

	points.push_back(x);

	for (float t = 0; t <= 1; t += 0.002) {
		float a = pow((1 - t), 2) * x->getX() + (2 * t * (1 - t) * z->getX()) + pow(t, 2)* y->getX();
		float b = pow((1 - t), 2) * x->getY() + (2 * t * (1 - t) * z->getY()) + pow(t, 2)* y->getY();

		points.push_back(new Point(a, b));
	}

	return points;
}