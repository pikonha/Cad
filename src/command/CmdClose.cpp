#include "CmdClose.h"
#include "CmdClearAllItems.h"

void CmdClose::execute(Data& d, MainScreen& s)
{
   d.deleteAllFiles();
   exit(0);
}