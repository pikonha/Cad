#include "CmdSetZoom.h"

void CmdSetZoom::execute(Data& d, MainScreen& s)
{
   d.getCurrentFile()->getView()->setScale(scale);

   double percent = (double)scale/100;

   d.getCurrentFile()->getView()->changeScale(percent);
   d.getCurrentFile()->reprint();
}
