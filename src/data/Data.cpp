#include "Data.h"

void Data::clearGeometries()
{
	for (int i = 0; i < allGeos.size(); i++)
		delete allGeos[i];

   allGeos.clear();
}



