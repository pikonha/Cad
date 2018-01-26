#include "MainCmdBezier.h"
#include "Bezier.h"
#include "Data.h"

void MainCmdBezier::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      bezier = new Bezier();
      bezier->setP1(p);
      auxLine->setP1(p);

      setMessageToScreen(MOUSEMOVE);
      setAuxDraw(true);
   }
   else
   {
      secondClick = true;
   }
}

void MainCmdBezier::mouseReleaseEvent(Point& p)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);

      bezier->setP2(p);

      data.getCurrentFile()->removeGeo(auxLine);
      delete auxLine;
   }
   else
   {
     data.getCurrentFile()->addGeo(bezier);
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      
      auxLine->setP2(p);

      data.getCurrentFile()->addGeo(auxLine);

      setMessageToScreen(MOUSEDRAG);
   }
   
   else if (drawing)
   {
      bezier->setP3(p);      
      data.getCurrentFile()->addGeo(bezier);
   }
}