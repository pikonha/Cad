#include "MainCmdArch.h"
#include "Arch.h"
#include "Data.h"

void MainCmdArch::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      arch.setP1(p);
      auxLine->setP1(p);
      
      setAuxDraw(true);

      setMessageToScreen(MOUSEMOVE);
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
      setMessageToScreen(SECONDCLICK);

      arch.setP2(p);

      delete auxLine;
   }
   else
      data.getCurrentFile()->addGeo(new Arch(arch));
    
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if (auxDraw) { 
      auxLine->setP2(p);      
      data.getCurrentFile()->getView()->draw(*auxLine);
   }
   
   else if( drawing )
   {
      arch.setP3(p); 
      data.getCurrentFile()->getView()->draw(arch);

   }
}

