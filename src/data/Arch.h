#pragma once
#ifndef INCLUDED_ARCH_H
#define INCLUDED_ARCH_H

#include <vector>
#include "Line.h"

class Arch : public Geometry
{
	Point p3;

	int getQuadrant(const Point& a);
	double getAngleArcSen(double cateto, double hipotenusa);
	Point findArchPoint(double auxAngle);
public:
   ~Arch() {}
   Arch(const Point& _p1,const Point& _p2,const Point& _p3) : Geometry(_p1,_p2), p3(_p3) {}

   Point& getP3() { return p3; }
   void setP3(const Point p) { p3 = p; }

	std::vector<Point> getPoints() override;
};


#endif