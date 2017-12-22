#include "CmdSave.h"
#include <fstream>
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"

void CmdSave::saveLine(std::ofstream& stream, Line& line)
{
   int form = 0;
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
   int form = 1;
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
   int form = 2;
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


void CmdSave::execute(Data& d, MainScreen& s)
{   
   std::string fileName = s.getSaveFileName();

   std::ofstream stream;

   std::deque<Geometry*> itens = d.getGeometries();

   stream.open(fileName, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

   if ( stream.is_open())
   {

      for ( int i= 0; i < itens.size(); i++)
      {
         Geometry* geo = itens.at(i);

         if (Line* line = dynamic_cast<Line*>(geo))
            saveLine(stream,*line);

         else if (Bezier* bezier= dynamic_cast<Bezier*>(geo))
            saveBezier(stream,*bezier);

         else if (Arch* arch = dynamic_cast<Arch*>(geo))
            saveArch(stream,*arch);
      }
   }
   else
   {
      s.errorMessage();
   } 
}
