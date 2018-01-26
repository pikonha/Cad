#include "CmdSave.h"
#include <fstream>
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"
#include "FormType.h"

void CmdSave::saveLine(std::ofstream& stream, Line& line)
{
   FormType form = LINE;
   stream.write((char*)&form,sizeof(int));

   int x = line.getP1().x;
   int y = line.getP1().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));
                       
   x = line.getP2().x;
   y = line.getP2().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));
}

void CmdSave::saveBezier(std::ofstream& stream, Bezier& bezier)
{
   FormType form = BEZIER;
   stream.write((char*)&form,sizeof(int));

   int x = bezier.getP1().x;
   int y = bezier.getP1().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));
                       
   x = bezier.getP2().x;
   y = bezier.getP2().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));

   x = bezier.getP3().x;
   y = bezier.getP3().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));
}

void CmdSave::saveArch(std::ofstream& stream, Arch& arch)
{
   FormType form = ARCH;
   stream.write((char*)&form,sizeof(int));

   int x = arch.getP1().x;
   int y = arch.getP1().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));

   x = arch.getP2().x;
   y = arch.getP2().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));

   x = arch.getP3().x;
   y = arch.getP3().y;
   stream.write((char*)&x,sizeof(int));
   stream.write((char*)&y,sizeof(int));
}

void CmdSave::saveScale(std::ofstream& stream, int scale)
{
   stream.write((char*)&scale,sizeof(int));
}

/////////////////////////////////////////////////////////////////////////

void CmdSave::execute(Data& d, MainScreen& s)
{   
   if (d.getCurrentFile()->getSaved())
      return;

   std::string path;

   if (d.getCurrentFile()->getPath().empty())
      path= d.getCurrentFile()->getView()->getSavePath();
   else
      path = d.getCurrentFile()->getPath();

   std::ofstream stream;

   d.getCurrentFile()->setPath(path);

   std::vector<Geometry*> itens = d.getCurrentFile()->getGeos();

   stream.open(path, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

   if ( stream.is_open())
   {
      d.getCurrentFile()->setName(s.getFileName(path));

      saveScale(stream,d.getCurrentFile()->getView()->getScale());

      for ( int i= 0; i < itens.size(); i++)
      {
         Geometry* geo = itens[i];

         if (Line* line = dynamic_cast<Line*>(geo))
            saveLine(stream,*line);

         else if (Bezier* bezier= dynamic_cast<Bezier*>(geo))
            saveBezier(stream,*bezier);

         else if (Arch* arch = dynamic_cast<Arch*>(geo))
            saveArch(stream,*arch);
      }

      s.tabs->setTabText(s.tabs->tabPosition(),d.getCurrentFile()->getName().c_str());
      d.getCurrentFile()->setSaved(true);
      d.getCurrentFile()->setPath(path);
   }
   else
   {
      s.errorMessage();
   } 
}
