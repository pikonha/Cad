#include "MainCmdArch.h"
#include "Arch.h"
#include "Data.h"

Geometry* MainCmdArch::getNewGeometry()
{
   if (arch) {
      data.getCurrentFile()->deleteGeo(arch);
      data.getCurrentFile()->getView()->eraseGeo(arch);
   }

   arch = new Arch(p1,p2,p3);

   return arch;
}

////////////////////////////////////////////////////////////////////////////////

void MainCmdArch::setP1(const Point& p)
{
   p1= p;
   //setMessageToScreen(MOUSEMOVE);
}

void MainCmdArch::setP2(const Point& p)
{
   p2= p;

   if (auxLine)
      data.getCurrentFile()->getView()->eraseGeo(auxLine);

   auxLine = new Line(p1,p2);
   data.getCurrentFile()->getView()->draw(auxLine);
}

void MainCmdArch::setP3(const Point& p)
{
   p3 = p;
   data.getCurrentFile()->getView()->eraseGeo(auxLine);
   data.getCurrentFile()->getView()->draw(getNewGeometry());

   delete auxLine;
   auxLine = nullptr;
}

////////////////////////////////////////////////////////////////////////////////

void MainCmdArch::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      setP1(p);
      setAuxDraw(true);
   }
   else
   {
      setDrawing(false);
      secondClick = true;
   }
}

void MainCmdArch::mouseReleaseEvent(Point& p)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);
      //setMessageToScreen(SECONDCLICK);
   }
   else
      data.getCurrentFile()->addGeo(arch);
    
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if ( auxDraw )   
      setP2(p);
   
   else if( drawing )
      setP3(p);
}

