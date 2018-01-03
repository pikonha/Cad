#include "CmdClearLastItem.h"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
   d.getCurrentFile()->deleteLastGeo();
}