#include "MainCmdLine.h"
#include "Geometry.h"
#include "LineModel.h"

void MainCmdLine::execute(Data& d, MainScreen& s)
{
	d.setForm(LINE);
	line= new Line();
}

void MainCmdLine::setP1(const Point& p)
{
	line->setP1(p);
}

void MainCmdLine::setP2(const Point& p)
{
	line->setP2(p);
	draw();
}	 


QGraphicsItem* MainCmdLine::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;

   geoModel = new LineModel(line);
   
   return geoModel;
}

void MainCmdLine::mousePressEvent(Point& p)
{
   setP1(p);
   setDrawing(true);
}

void MainCmdLine::mouseReleaseEvent(Point& p, Data& d)
{
   screen.getView()->save(getQtGraphicGeo());
   d.addGeometry(&getGeometry());

   setDrawing(false);
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(p);
}
