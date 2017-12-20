#include "CmdLoad.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QMap>

void CmdLoad::execute(Data& d, MainScreen& s) 
{
   const QString fileName = QFileDialog::getOpenFileName(s.getView(),QString("Save File"),"",QString("Dat files (*.dat)"));

   QFile file(fileName);

   QMap<qint64,int> mapX;
   QMap<qint64,int> mapY;

   QDataStream in(&file);
   in.setVersion(QDataStream::Qt_5_9);

   if (file.open(QIODevice::ReadOnly))
   {
      in >> mapX;
      in >> mapY;

      file.close();
   }
   else
      QMessageBox::information(s.getView(),QString("Unable to open file"),file.errorString());
}