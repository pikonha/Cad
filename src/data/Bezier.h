#pragma once
#ifndef INCLUDED_BEZIER_H
#define INCLUDED_BEZIER_H
#include "Item.h"
#include <vector>
#include "Point.h"

class Bezier : public Item
{
private:
	Point z;

public:
	Bezier() {}
	Bezier(Point a, Point b, Point c) : Item(a, b) { z = c; }
	~Bezier() {}

	std::vector<Point> getPoints();
};


#endif