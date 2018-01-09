#include "CmdClearAllItems.h"

void CmdClearAllItems::execute(Data& d, MainScreen& s)
{
   d.getCurrentFile()->deleteAllGeos();
}