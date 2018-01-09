#include "CmdNewFile.h"
#include <QDialog>
#include "View.h"
#include "STRUCTNEWFILE.h"

void CmdNewFile::execute(Data& d, MainScreen& s)
{
   STRUCTNEWFILE dialog = s.newFileDialog();
   if (dialog.dialogExec == QDialog::Accepted) 
   {
      View* view = new View(s.getManager(),dialog.width,dialog.height,&s);
      File* file = new File(dialog.name,view);

      d.setCurrentFile(file);
      d.addFIle(file);
      
      s.addTab(file->getView(),file->getName());

      s.tabs->setVisible(true);
      view->show();
   }
}
