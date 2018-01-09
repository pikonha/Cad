#include "CmdCloseTab.h"
#include "File.h"

void CmdCloseTab::execute(Data& d, MainScreen& s)
{
   File* f = d.getFileByView(dynamic_cast<View*>(view));

   if ( f )
   {
      if (!f->getSaved())
         s.closeTabDialog();

      else
         s.tabs->removeTab(s.tabs->tabPosition());
   
      if (s.tabs->count() <= 0)
         s.tabs->setVisible(false);
   }
}
