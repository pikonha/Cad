#include "MainCmdLine.h"
#include "Item.h"

void MainCmdLine::execute(Data& d, MainScreen& s)
{
	d.setForm(LINE);
	line = new Line();
}

void MainCmdLine::setP1(Point p)
{
	line->setX(p);
}

void MainCmdLine::setP2(Point p)
{
	line->setY(p);
	draw();
}	 


QGraphicsItem* MainCmdLine::getModel()
{
	return new LineModel(line);
}
