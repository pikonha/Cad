#include "CmdDiscard.h"

void CmdDiscard::execute(Data& d, MainScreen& s)
{
   View* view = dynamic_cast<View*>(s.tabs->widget(tab));

   d.deleteFile(&view->getFile());
   s.deleteView(view);
}
