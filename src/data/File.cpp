#include "File.h"

void File::deleteAllGeos()
{
   for (int i= 0; i < geometries.size(); i++)
      delete geometries[i];

   geometries.clear();
}

////////////////////////////////////////////////////////////////////////////////

void File::deleteLastGeo()
{
   delete getLastGeometry();
   geometries.clear();
}

void File::reprint()
{
   for (int i= 0; i < geometries.size(); i++)
      draw(geometries[i]);
}

void File::draw(Geometry* geo)
{
   std::vector<Point> points = geo->getPoints();

   for (int i= 0; i < points.size(); i++)
      view.getPainter().drawPoint(points.at(i).x,points.at(i).y);
}

void File::drawAuxLine(const Point p1, const Point p2)
{
   view.getPainter().drawLine(View::pointToQPoint(p1),View::pointToQPoint(p2));
}
