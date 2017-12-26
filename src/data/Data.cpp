#include "Data.h"


void Data::clearGeometries()
{
   std::vector<Geometry*> geos = currentFile->getGeos();

   for ( int i= 0; i < geos.size(); i++ )
      delete geos[i];

   geos.clear();
}
