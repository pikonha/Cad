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
   data.getCurrentFile()->addGeo(new Line(line));
   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   if (drawing) {
      data.getCurrentFile()->getView()->eraseGeo(&line);

      line.setP2(p);
      data.getCurrentFile()->getView()->draw(&line);
   }
}
