#include "File.h"

void File::deleteAllGeos()
{
   geometries.clear();
   reprint();
}

void File::addGeo(Geometry* geo)
{
   removeGeo(geo);
   geometries.push_back(geo);
   
   reprint();
}

void File::removeGeo(Geometry* geo)
{
   for (int i= 0; i < geometries.size(); i++) {
      if (geometries[i] == geo)
         geometries.erase(geometries.begin() + i);      
   }
}

////////////////////////////////////////////////////////////////////////////////

void File::reprint()
{
   view->clearPixmap();
   view->update();

   for (auto geo : geometries)
      view->drawInPixmap(*geo);

   view->update();
}

