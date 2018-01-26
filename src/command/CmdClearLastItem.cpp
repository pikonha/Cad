#include "CmdClearLastItem.h"

void CmdClearLastItem::execute(Data& d,MainScreen& s)
{
   if (d.getCurrentFile()->getGeos().size() > 0){
      d.getCurrentFile()->removeGeo(d.getCurrentFile()->getLastGeometry());
      d.getCurrentFile()->reprint();
   }
}