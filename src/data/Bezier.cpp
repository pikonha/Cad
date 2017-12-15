#include "Bezier.h"


std::vector<Point*> Bezier::getPoints()
{
	std::vector<Point*> points;

	points.push_back(x);

	for (float t = 0 ; t <= 1 ; t += 0.002f ) {
		float a = pow((1 - t), 2) * x->x + (2 * t * (1 - t) * z->x) + pow(t, 2)* y->x;
		float b = pow((1 - t), 2) * x->y + (2 * t * (1 - t) * z->y) + pow(t, 2)* y->y;

		points.push_back(new Point(int(a), int(b)));
	}

	return points;
}