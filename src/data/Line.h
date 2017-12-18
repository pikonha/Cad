#pragma once 
#ifndef INCLUDED_LINE_H
#define INCLUDED_LINE_H
#include "Item.h"
#include "Point.h"

class Line : public Item
{
public:
	Line() : Item() {}
	Line(Point* a, Point* b) : Item(a,b) {}
	~Line() {}

	std::vector<Point*> getPoints();
};

#endif