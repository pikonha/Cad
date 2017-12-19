#pragma once
#ifndef INCLUDED_BEZIER_H
#define INCLUDED_BEZIER_H
#include "Geometry.h"
#include <vector>
#include "Point.h"

class Bezier : public Geometry
{
private:
	Point p3;

public:
	Bezier() : Geometry() {}
	Bezier(const Point& _p1, const Point& _p2, const Point& _p3) : Geometry(_p1, _p2) { p3 = _p3; }
	~Bezier() {}

	void setZ(const Point& p) { p3 = p; }

	std::vector<Point> getPoints() override;
};


#endif