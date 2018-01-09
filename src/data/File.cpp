#include "File.h"

void File::deleteAllGeos()
{
   for (int i= 0; i < geometries.size(); i++)
      delete geometries[i];

   geometries.clear();
}

void File::deleteGeo(Geometry* geo)
{
   for (Geometry* g : geometries)
      if (g == geo) {
         view->eraseGeo(g);
         delete g;
         geometries.clear();
      }

   view->update();
}

////////////////////////////////////////////////////////////////////////////////

void File::deleteLastGeo()
{
   delete getLastGeometry();
   geometries.clear();
}

void File::reprint()
{
   for ( Geometry* geo : geometries)
      view->draw(geo);
}

void File::drawAuxLine(const Point p1, const Point p2) const
{
   view->drawAuxLine(p1,p2);
}
