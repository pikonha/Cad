#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute()
{
	data->setForm(BEZIER);
	bezier = new Bezier();
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
	draw();
}

void MainCmdBezier::draw()
{
	BezierModel* b = new BezierModel(bezier);
	view->getScene()->addItem(b);
}
