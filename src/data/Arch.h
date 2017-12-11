#pragma once
#ifndef INCLUDED_ARCH_H
#define INCLUDED_ARCH_H
#include "Point.h"
#include "Item.h"
#include <vector>

class Line;

class Arch : public Item
{
private:
	Point* z;

	Line* raio;
	double angle;
	Point* center;
	Point* control;


	double pointDistance(Point* x, Point* y);
	int getQuadrant(Point* a);
	double getAngleArcSen(double cateto, double hipotenusa);
	Point findArchPoint(double auxAngle);

public:
	Arch() {}
	Arch(Point* a, Point* b, Point* c);
	~Arch() {}

	std::vector<Point*> getPoints();

	void setZ(Point* p) { z = p; }
};


#endif