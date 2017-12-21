#include "MainCmdLine.h"
#include "Geometry.h"
#include "LineModel.h"

void MainCmdLine::execute(Data& d, MainScreen& s)
{
	d.setForm(LINE);
}

void MainCmdLine::setP1(const Point& p)
{
	p1= p;
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
   screen.getView()->save(geoModel);
   d.addGeometry(getNewGeometry());

   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(p);
}
