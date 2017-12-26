#include "CmdClearLastItem.h"
#include "Geometry.h"
#include "QGraphicsItem"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
   std::vector<Geometry*>* geos = &s.getCurrentView().getFile().getGeos();

   if (geos->size() > 0)
   {
      delete geos->back();

      geos->pop_back();
   }   

   geos->clear();
}