#include "CmdLoad.h"
#include "fstream"
#include "Line.h"
#include "Arch.h"
#include "Bezier.h"
#include "LineModel.h"
#include "BezierModel.h"
#include "ArchModel.h"

void CmdLoad::execute(Data& d, MainScreen& s) 
{
   std::string fileName = s.getLoadPath();

   std::ifstream stream;

   std::deque<Geometry*> itens;

   stream.open(fileName, std::ios::in | std::ios::binary);    

   if (stream.is_open())
   {
      stream.seekg(0);

      int form;
      int p1x;
      int p1y;
      int p2x;
      int p2y;
      int p3x;
      int p3y;

      while (!stream.eof())
      {
         stream.read((char*)&form,sizeof(int));

         stream.read((char*)&p1x,sizeof(int));
         stream.read((char*)&p1y,sizeof(int));

         stream.read((char*)&p2x,sizeof(int));
         stream.read((char*)&p2y,sizeof(int));

         if (form > 0)
         {
            stream.read((char*)&p3x,sizeof(int));
            stream.read((char*)&p3y,sizeof(int));
         }

         Line *ln;
         Arch *a;
         Bezier *bz;
         Geometry* geo;
         QGraphicsItem* model;

         switch (form)
         {
         case 0:
            geo= ln= new Line(Point(p1x,p1y),Point(p2x,p2y));
            model = new LineModel(*ln);
            break;

         case 1:
            geo= bz= new Bezier(Point(p1x,p1y),Point(p2x,p2y),Point(p3x,p3y));
            model = new BezierModel(*bz);
            break;

         case 2:
            geo= a= new Arch(Point(p1x,p1y),Point(p2x,p2y),Point(p3x,p3y));
            model = new ArchModel(*a);
            break;
         }

         s.getCurrentView().draw(model);
         s.getCurrentView().save(model);
         itens.push_back(geo);
      }
   }
   else
      s.errorMessage();
}
