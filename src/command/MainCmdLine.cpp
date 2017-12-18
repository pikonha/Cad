#include "MainCmdLine.h"
#include "Item.h"
#include "LineModel.h"

void MainCmdLine::execute(Data& d, MainScreen& s)
{
	d.setForm(LINE);
	line = new Line();
}

void MainCmdLine::setP1(Point* p)
{
	line->setX(p);
}

void MainCmdLine::setP2(Point* p)
{
	line->setY(p);
	draw();
}	 


QGraphicsItem* MainCmdLine::getModel()
{
	return new LineModel(line);
}

void MainCmdLine::mousePressEvent(Point& p)
{
   setP1(&p);
   setDrawing(true, screen.getView());
}

void MainCmdLine::mouseReleaseEvent(Point& p, Data& d)
{
   screen.getView()->save(getModel());
   d.addItem(getItem());

   setDrawing(false, screen.getView());
}

void MainCmdLine::mouseMoveEvent(Point& p)
{
   setP2(&p);
}
