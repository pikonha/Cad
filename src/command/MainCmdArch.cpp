#include "MainCmdArch.h"
#include "Arch.h"
#include "Data.h"

Geometry* MainCmdArch::getNewGeometry()
{
   if (arch)
      delete arch;

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
}

void MainCmdArch::setP3(const Point& p)
{
   p3 = p;
	data.getCurrentFile()->draw(getNewGeometry());
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
      data.getCurrentFile()->addGeo(getNewGeometry());
    
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if ( auxDraw )
   {
      setP2(p);
      data.getCurrentFile()->getView()->drawAuxLine(p1,p2);
   }
   else if( drawing )
      setP3(p);
}

