#pragma once 
#ifndef INCLUDED_LINE_H
#define INCLUDED_LINE_H
#include "Geometry.h"
#include "Point.h"

class Line : public Geometry
{
public:
   ~Line() {}
   Line(const Line& l) : Geometry(l.p1,l.p2) {}
   Line(const Point& _p1, const Point& _p2) : Geometry(_p1, _p2) {}	

	std::vector<Point> getPoints() override;
};

#endif