#include "CmdNewFile.h"
#include "NewFileWidget.h"

void CmdNewFile::execute(Data& d,MainScreen& s)
{
   File* file = new File(s.bottomBar->getText(),s.createView());

   d.setCurrentFile(file);
   d.addFIle(file);

   s.addTab(file->getView(),file->getName());

   s.slider->setValue(10);
   s.tabs->setVisible(true);

}
