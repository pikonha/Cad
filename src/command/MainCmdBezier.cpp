#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute(Data& d, MainScreen& s)
{
	d.setForm(BEZIER);
	bezier = new Bezier();
}

void MainCmdBezier::setP1(Point* p)
{
	bezier->setX(p);
}

void MainCmdBezier::setP2(Point* p)
{
	bezier->setY(p);
}

void MainCmdBezier::setP3(Point* p)
{
	bezier->setZ(p);

	draw();
}

QGraphicsItem* MainCmdBezier::getModel()
{
	return new BezierModel(bezier);
}