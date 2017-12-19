#pragma once
#ifndef INCLUDED_ARCH_H
#define INCLUDED_ARCH_H

#include <vector>
#include "Line.h"

class Arch : public Geometry
{
private:
	Point p3;

	Line raio;
	double angle;
	Point center;
	Point control;

	int getQuadrant(const Point& a);
	double getAngleArcSen(double cateto, double hipotenusa);
	Point findArchPoint(double auxAngle);

public:
   ~Arch() {}

	Arch() : Geometry() {}
   Arch(const Point& _p1, const Point& _p2, const Point& _p3);	

	std::vector<Point> getPoints() override;

	void setP3(const Point& p) { p3 = p; }

	void setRaio() { raio= Line(p1, p2); }

	void setCenter( const Point& p) { center = p; }
	void setControl( const Point& p) { control = p; }
};


#endif