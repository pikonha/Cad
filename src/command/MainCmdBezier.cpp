#include "MainCmdBezier.h"
#include "Bezier.h"
#include "Data.h"

void MainCmdBezier::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      bezier.setP1(p);
      auxLine->setP1(p);

      setMessageToScreen(MOUSEMOVE);
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

      data.getCurrentFile()->getView()->eraseGeo(auxLine);
      delete auxLine;
   }
   else
   {
     data.getCurrentFile()->addGeo(new Bezier(bezier));
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      data.getCurrentFile()->getView()->eraseGeo(auxLine);
      bezier.setP2(p);
      auxLine->setP2(p);

      data.getCurrentFile()->getView()->draw(auxLine);

      setMessageToScreen(MOUSEDRAG);
   }
   
   else if (drawing)
   {
      data.getCurrentFile()->getView()->eraseGeo(&bezier);
      bezier.setP3(p);      
      data.getCurrentFile()->getView()->draw(&bezier);
   }
}