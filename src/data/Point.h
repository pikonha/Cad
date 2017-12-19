#pragma once
#ifndef INCLUDED_POINT_H
#define INCLUDED_POINT_H

#include <math.h>

class Point
{
public:
	int x,y;

public:
   Point() : x(0), y(0) {}
	Point(int _x,int _y) : x(_x), y(_y) {}

	bool operator==(const Point& p);
   Point& operator=(const Point& p);

   
   static double distance(const Point& p1,const Point& p2) {
      Point dif= difference(p1,p2);
      return sqrt(pow(dif.x,2) + pow(dif.y,2));
   }

   static Point difference(const Point& p1,const Point& p2) {
      return Point((p2.x - p1.x),(p2.y - p1.y));
   }
};



#endif