#include "MainCmdLine.h"
#include "Item.h"

void MainCmdLine::execute()
{
	data->setForm(LINE);
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
	 
void MainCmdLine::draw()
{
	LineModel* model = new LineModel(line);
	screen->getView()->getScene()->addItem(model);
}


void MainCmdLine::pressMouse()
{
	setP1(*screen->getView()->getMousePos());
}

void MainCmdLine::moveMouse()
{
	setP2(*screen->getView()->getMousePos());
}

void MainCmdLine::releaseMouse()
{
	data->addItem(line);
}