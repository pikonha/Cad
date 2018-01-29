#include "CmdSetZoom.h"

void CmdSetZoom::execute(Data& d, MainScreen& s)
{
   d.getCurrentFile()->getView()->setScale(scale);
}
