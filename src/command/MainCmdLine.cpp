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
   data.getCurrentFile()->addGeo(&line);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   if (drawing) {
      data.getCurrentFile()->getView()->removePath(&line);

      line.setP2(p);
      data.getCurrentFile()->getView()->addPath(&line);

      data.getCurrentFile()->reprint();
   }
}
