#pragma once
#ifndef INCLUDED_POINT_H
#define INCLUDED_POINT_H

class Point
{
private:
	int x;
	int y;

public:
	Point() {}
	Point(int a, int b) { x = a; y = b; }
	~Point() {}

	int getX() { return x; }
	int getY() { return y; }

	bool operator==(Point* p);
};

#endif