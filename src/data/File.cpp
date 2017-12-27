#include "File.h"


void File::deleteAllGeos()
{
   for (int i= 0; i < geometries.size(); i++)
      delete geometries[i];

   geometries.clear();
}
