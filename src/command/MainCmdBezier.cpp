#include "MainCmdBezier.h"
#include "Bezier.h"
#include "Data.h"

void MainCmdBezier::setP1(const Point& p)
{
   p1= p;
  // setMessageToScreen(MOUSEMOVE);
}

void MainCmdBezier::setP2(const Point& p)
{
   p2= p;
}

void MainCmdBezier::setP3(const Point& p)
{
   p3= p;
	data.getCurrentFile()->draw(getNewGeometry());
}

Geometry* MainCmdBezier::getNewGeometry()
{
   if (bezier)
      delete bezier;

   bezier = new Bezier(p1,p2,p3);

   return bezier;
}

void MainCmdBezier::mousePressEvent(Point& p)
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

void MainCmdBezier::mouseReleaseEvent(Point& p)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);
      //setMessageToScreen(SECONDCLICK);
   }
   else
   {
     data.getCurrentFile()->addGeo(getNewGeometry());
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      setP2(p);
      data.getCurrentFile()->drawAuxLine(p1,p2);
   }
   else if (drawing)
      setP3(p);
}