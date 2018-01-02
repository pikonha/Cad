#include "CmdNewFile.h"
#include "../app/App.h"
#include <vector>
#include <QDialog>

void CmdNewFile::execute(Data& d, MainScreen& s)
{
   if (s.newFileDialog() == QDialog::Accepted) 
   {
      View* view = new View(s.getPainter(),&s);
      view->setManager(App::getInstance().getManager());

      s.getViews()->push_back(view);
      s.setCurrentView(view);

      d.getFiles().push_back(&view->getFile());
      d.setCurrentFile(&view->getFile());

      s.addTab(view,view->getFile().getName());

      view->show();
   }
}
