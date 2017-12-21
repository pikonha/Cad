#include "CmdClose.h"
#include "CmdClearAllItems.h"

void CmdClose::execute(Data& d, MainScreen& s)
{
   CmdClearAllItems().execute(d,s);
}