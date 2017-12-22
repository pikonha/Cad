#include "MainCmd.h"

void MainCmd::createAuxLine(const Point& p, const Point& o)
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
	screen.getView()->draw(getQtGraphicGeo());
}

void MainCmd::setMessageToScreen(Instruction in)
{ 
   screen.setStatusMessage(in);
}

