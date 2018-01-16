#include "CmdNewFile.h"
#include "View.h"
#include "STRUCTNEWFILE.h"

void CmdNewFile::execute(Data& d, MainScreen& s)
{
   STRUCTNEWFILE dialog = s.newFileDialog();

   View* view = s.createView(dialog.exec,dialog.width, dialog.height);

   if ( view ){
      File* file = new File(dialog.name,view);

      d.setCurrentFile(file);
      d.addFIle(file);
      
      s.addTab(file->getView(),file->getName());

      s.slider->setValue(view->getScale() / 10);
      s.tabs->setVisible(true);
   }
}
