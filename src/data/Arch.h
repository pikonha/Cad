#pragma once
#ifndef INCLUDED_ARCH_H
#define INCLUDED_ARCH_H
#include "Point.h"
#include "Item.h"
#include <vector>
#include "Line.h"

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
	Point* findArchPoint(double auxAngle);

public:
	Arch() : Item() { z = new Point(); }
	Arch(Point* a, Point* b, Point* c);
	~Arch() {}

	std::vector<Point*> getPoints() override;

	void setZ(Point* p) { delete z; z = p; }

	void setRaio() { raio = new Line(x, y); }

	void setCenter(Point* p) { center = p; }
	void setControl(Point* p) { control = p; }
};


#endif