#include "CmdNewFile.h"
#include <QDialog>
#include "View.h"
#include "../app/App.h"

void CmdNewFile::execute(Data& d, MainScreen& s)
{
   if (s.newFileDialog() == QDialog::Accepted) 
   {
      View* view = new View(&App::getInstance().getManager(),&s);
      File* file = new File(view);

      d.setCurrentFile(file);
      d.addFIle(file);
      
      s.addTab(file->getView(),file->getName());

      view->show();
   }
}
