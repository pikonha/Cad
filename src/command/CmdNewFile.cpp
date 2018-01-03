#include "CmdNewFile.h"
#include <QDialog>

void CmdNewFile::execute(Data& d, MainScreen& s)
{
   if (s.newFileDialog() == QDialog::Accepted) 
   {
      View* view;
      File* file = new File(*view);

      d.setCurrentFile(file);
      d.addFIle(file);
      
      s.addTab(&file->getView(),file->getName());

      view->show();
   }
}
