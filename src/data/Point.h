#pragma once
#ifndef INCLUDED_POINT_H
#define INCLUDED_POINT_H

class Point
{
public:
	int x;
	int y;

public:
   Point() : x(0), y(0) {}
	Point(int _x,int _y) : x(_x), y(_y) {}

	bool operator==(const Point& p);
   Point& operator=(const Point& p);
};

#endif