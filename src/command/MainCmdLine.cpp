#include "MainCmdLine.h"
#include "Data.h"
//#include "Instruction.h"

Geometry* MainCmdLine::getNewGeometry()
{
   if (line) {
      data.getCurrentFile()->deleteGeo(line);
      data.getCurrentFile()->getView()->eraseGeo(line);
   }

   line = new Line(p1,p2);

   return line;
}

////////////////////////////////////////////////////////////////////////////////

void MainCmdLine::setP1(const Point& p)
{
	p1= p;
  /* setMessageToScreen(MOUSEMOVE);*/
}

void MainCmdLine::setP2(const Point& p)
{
   if (drawing) {
      p2= p;
      data.getCurrentFile()->getView()->draw(getNewGeometry());
   }
}

////////////////////////////////////////////////////////////////////////////////

void MainCmdLine::mousePressEvent(Point& p)
{
   setP1(p);
   setDrawing(true);
}

void MainCmdLine::mouseReleaseEvent(Point& p)
{
   data.getCurrentFile()->addGeo(line);
   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(p);
}
