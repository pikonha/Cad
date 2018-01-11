#include "CmdDiscard.h"

void CmdDiscard::execute(Data& d, MainScreen& s)
{
   d.deleteFile(d.getCurrentFile());
   s.tabs->removeTab(s.tabs->tabPosition());
}
