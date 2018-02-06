#include "MainCmdArch.h"
#include "Arch.h"
#include "Data.h"

void MainCmdArch::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      arch = new Arch();
      arch->setP1(p);
      auxLine->setP1(p);
      
      setAuxDraw(true);

      setMessageToScreen(MOUSEMOVE);
   }
   else
      secondClick = true;
}

void MainCmdArch::mouseReleaseEvent(Point& p)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);
      setMessageToScreen(SECONDCLICK);

      arch->setP2(p);

      data.getCurrentFile()->removeGeo(auxLine);
      delete auxLine;
   }
   else {
      data.getCurrentFile()->addGeo(arch);
      data.getCurrentFile()->getView()->setDraw(false);
   }
    
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if (auxDraw) { 
      auxLine->setP2(p); 

      data.getCurrentFile()->addGeo(auxLine);
   }
   
   else if( drawing )
   {
      arch->setP3(p); 
      data.getCurrentFile()->addGeo(arch);

   }
}

