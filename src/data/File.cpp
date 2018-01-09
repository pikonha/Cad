#include "File.h"

void File::deleteAllGeos()
{
   for (int i= 0; i < geometries.size(); i++) {
      view->eraseGeo(geometries[i]);
      delete geometries[i];
   }

   geometries.clear();
}

void File::deleteGeo(Geometry* geo)
{
   for (Geometry* g : geometries) {
      if (g == geo) {
         view->eraseGeo(g);
         delete g;
         geometries.clear();
      }
   }

   view->update();
}

////////////////////////////////////////////////////////////////////////////////

void File::deleteLastGeo()
{
   if (geometries.size() > 0) {
      view->eraseGeo(geometries.back());
      delete getLastGeometry();
      geometries.clear();
   }
}

void File::reprint()
{
   for ( Geometry* geo : geometries)
      view->draw(geo);
}

