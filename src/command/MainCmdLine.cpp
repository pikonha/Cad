#include "MainCmdLine.h"
#include "Data.h"

////////////////////////////////////////////////////////////////////////////////

void MainCmdLine::mousePressEvent(Point& p)
{
   line = new Line(p,p);

   drawing= true;

   setMessageToScreen(MOUSEMOVE);
}

void MainCmdLine::mouseReleaseEvent(Point& p)
{
   setDrawing(false);
   data.getCurrentFile()->addGeo(line);
   data.getCurrentFile()->getView()->setDraw(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   if (drawing) {
      line->setP2(p);
      data.getCurrentFile()->addGeo(line);
   }
}
