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

void File::draw(Geometry* geo) const
{
   view->draw(geo);
}

void File::drawAuxLine(const Point p1, const Point p2) const
{
   view->drawAuxLine(p1,p2);
}
