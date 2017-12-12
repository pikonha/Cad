#include "MainCmd.h"

void MainCmd::createAuxLine(Point* p, Point* o)
{
	if (auxLine)
		delete auxLine;

	auxLine = new AuxLineModel(p, o);
}

AuxLineModel* MainCmd::getAuxLine()
{
	return auxLine;
}

void MainCmd::draw()
{
	screen->getView()->draw(getModel());
}