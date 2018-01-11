#include "MainCmdBezier.h"
#include "Bezier.h"
#include "Data.h"

void MainCmdBezier::setP1(const Point& p)
{
   p1= p;
   setMessageToScreen(MOUSEMOVE);
}

void MainCmdBezier::setP2(const Point& p)
{
   p2= p;

   if (auxLine)
      data.getCurrentFile()->getView()->eraseGeo(auxLine);

   auxLine = new Line(p1,p2);
   data.getCurrentFile()->getView()->draw(auxLine);

   setMessageToScreen(MOUSEDRAG);
}

void MainCmdBezier::setP3(const Point& p)
{
   p3= p;
   data.getCurrentFile()->getView()->eraseGeo(auxLine);
   data.getCurrentFile()->getView()->draw(getNewGeometry());	

   delete auxLine;
   auxLine = nullptr;
}

Geometry* MainCmdBezier::getNewGeometry()
{
   if (bezier) {
      data.getCurrentFile()->deleteGeo(bezier);
      data.getCurrentFile()->getView()->eraseGeo(bezier);
   }

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
   }
   else
   {
     data.getCurrentFile()->addGeo(bezier);
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)   
      setP2(p);
   
   else if (drawing)
      setP3(p);
}