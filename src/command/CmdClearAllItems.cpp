#include "CmdClearAllItems.h"
#include "QGraphicsItem"
#include "Geometry.h"

void CmdClearAllItems::execute(Data& d, MainScreen& s)
{
   std::vector<Geometry*>* geos = &s.getCurrentView().getFile().getGeos();

   for (int i= 0; i < geos->size(); i++)
      delete geos->at(i);

   geos->clear();

   s.getCurrentView().getScene()->update();   
}