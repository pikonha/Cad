#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute()
{
	data->setForm(BEZIER);
}

void MainCmdBezier::setP1(Point p)
{
	bezier->setX(p);
}

void MainCmdBezier::setP2(Point p)
{
	bezier->setY(p);
}

void MainCmdBezier::setP3(Point p)
{
	bezier->setZ(p);
}

void MainCmdBezier::draw()
{
	BezierModel* b = new BezierModel(bezier);
	screen->getView()->getScene()->addItem(b);
}

void MainCmdBezier::pressMouse()
{
	setP1(*screen->getView()->getMousePos());
}

void MainCmdBezier::moveMouse()
{
	if ( !drawingBezier )
		setP2(*screen->getView()->getMousePos());
	else
		setP3(*screen->getView()->getMousePos());

	draw();
}

void MainCmdBezier::releaseMouse()
{
	drawingBezier = true;
}