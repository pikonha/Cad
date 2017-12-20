#pragma once
#ifndef INCLUDED_GEOMETRY_H
#define INCLUDED_GEOMETRY_H

#include "Point.h"
#include <vector>

class Geometry
{
protected:
	Point p1, p2;

public:
   virtual ~Geometry() {}

   Geometry() { }
   Geometry(const Point& _p1, const Point& _p2) { p1 = _p1; p2 = _p2; }	

	Point& getP1() { return p1; }
	Point& getP2() { return p2; }

	void setP1(const Point& _p1) { p1 = _p1; }
	void setP2(const Point& _p2) { p2 = _p2; }

	virtual std::vector<Point> getPoints() = 0;

	bool operator==(const Geometry& i);
};

#endif