#include "Line.h"

std::vector<Point> Line::getPoints()
{
   std::vector<Point> points;

   points.push_back(p1);

   int x= p1.x;
   int y= p1.y;

   int distanceY = p2.y - p1.y;
   int distanceX = p2.x - p1.x;
   int stepX,stepY;

   distanceY < 0 ? stepY= -1 : stepY= 1;
   distanceY *= stepY;

   distanceX < 0 ? stepX= -1 : stepX= 1;
   distanceX *= stepX;

   if (distanceX > distanceY) {
      for (int fraction= distanceY - distanceX ; x != p2.x ; points.push_back(Point(x,y))) {
         if (fraction >= 0) {
            y += stepY;
            fraction -= distanceX;
         }
         x += stepX;
         fraction += distanceY;
      }
   }
   else {
      for (int fraction = distanceX - distanceY ; y != p2.y ; points.push_back(Point(x,y))) {
         if (fraction >= 0) {
            x += stepX;
            fraction -= distanceY;
         }
         y += stepY;
         fraction += distanceX;
      }
   }
   

	return points;
}