#include "CmdSave.h"
#include "QFileDialog"
#include "QMessageBox"

void CmdSave::execute(Data& d, MainScreen& s)
{
   QString fileName = QFileDialog::getSaveFileName(s.getView(),QString("Save File"),"",QString("Dat files (*.dat)"));

   if (fileName.isEmpty())
      return;

   else
   {
      QFile file(fileName);
      if ( !file.open(QIODevice::WriteOnly))
      {
         QMessageBox::information(s.getView(), QString("Unable to open file"),
            file.errorString());
         return;
      }
   }
      

}