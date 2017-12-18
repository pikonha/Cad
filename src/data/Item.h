#pragma once
#ifndef	INCLUDED_ITEM_H
#define INCLUDED_ITEM_H
#include "Point.h"
#include <vector>

class Item
{
protected:
	Point* x;
	Point* y;

public:
   virtual ~Item() { delete x; delete y; }
	Item() { x = new Point(); y = new Point(); }
	Item(Point* a, Point* b) { x = a; y = b; }
	

	Point* getP1() { return x; }
	Point* getP2() { return y; }

	void setX(Point* a) { x = a; }
	void setY(Point* b) { y = b; }

	virtual std::vector<Point*> getPoints() = 0;

	bool operator==(Item* i);
};

#endif