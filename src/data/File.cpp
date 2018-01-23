#include "File.h"

void File::deleteAllGeos()
{
   //for (int i= 0; i < geometries.size(); i++) 
   //   delete geometries[i];

   geometries.clear();
   reprint();
}

void File::deleteGeo(Geometry* geo)
{
   for (Geometry* g : geometries) {
      if (g == geo) 
         delete g;   
   }

   reprint();
   view->update();
}

void File::removeGeo(Geometry* geo)
{
   for (int i= 0; i < geometries.size(); i++) {
      if (geometries[i] == geo)
         geometries.erase(geometries.begin() + i);
   }
}

void File::deleteLastGeo()
{
   if (geometries.size() > 0) {
      delete geometries.back();
      reprint();
   }
}

////////////////////////////////////////////////////////////////////////////////

void File::reprint()
{
   view->clearImg();

   for ( Geometry* geo : geometries)
      view->draw(*geo);
}

