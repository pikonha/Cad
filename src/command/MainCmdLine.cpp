#include "MainCmdLine.h"
#include "Data.h"

////////////////////////////////////////////////////////////////////////////////

void MainCmdLine::mousePressEvent(Point& p)
{
   line.setP1(p);
   line.setP2(p);

   drawing= true;

   setMessageToScreen(MOUSEMOVE);
}

void MainCmdLine::mouseReleaseEvent(Point& p)
{
   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   if (drawing) {
      data.getCurrentFile()->removeGeo(&line);

      line.setP2(p);
      data.getCurrentFile()->addGeo(&line);

      data.getCurrentFile()->reprint();
   }
}
