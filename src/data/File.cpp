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
   
}

void File::addGeo(Geometry* geo)
{
   removeGeo(geo);

   geometries.clear();

   geometries.push_back(geo); 
   
   reprint();
}

void File::removeGeo(Geometry* geo)
{
   for (int i= 0; i < geometries.size(); i++) {
      if (geometries[i]->operator==(*geo))
      {
         geometries.erase(geometries.begin() + i);
      }
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
   view->clearView();

   for (auto geo : geometries)
      view->addPath(geo);
}

