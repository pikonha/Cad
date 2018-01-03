#include "MainCmdLine.h"
#include "Data.h"
//#include "Instruction.h"

void MainCmdLine::setP1(const Point& p)
{
	p1= p;
  /* setMessageToScreen(MOUSEMOVE);*/
}

void MainCmdLine::setP2(const Point& p)
{
   if (drawing) {
      p2= p;
      data.getCurrentFile()->draw(getNewGeometry());
   }
}

Geometry* MainCmdLine::getNewGeometry()
{
   if (line)
      delete line;

   line = new Line(p1,p2);

   return line;
}


void MainCmdLine::mousePressEvent(Point& p)
{
   setP1(p);
   setDrawing(true);
}

void MainCmdLine::mouseReleaseEvent(Point& p)
{
   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(p);
}
