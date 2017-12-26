#include "MainCmdLine.h"
#include "LineModel.h"
#include "Instruction.h"

void MainCmdLine::execute(Data& d, MainScreen& s)
{
	d.setForm(LINE);
   setMessageToScreen(MOUSECLICK);
}

void MainCmdLine::setP1(const Point& p)
{
	p1= p;
   setMessageToScreen(MOUSEMOVE);
}

void MainCmdLine::setP2(const Point& p)
{
	p2= p;
	draw();
}	

QGraphicsItem* MainCmdLine::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;     

   geoModel= new LineModel(Line(p1,p2));
   
   return geoModel;
}

void MainCmdLine::mousePressEvent(Point& p)
{
   setP1(p);
   setDrawing(true);
}

void MainCmdLine::mouseReleaseEvent(Point& p, Data& d)
{
   screen.getCurrentView().save(geoModel);
   d.addGeometry(getNewGeometry());

   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(p);
}
