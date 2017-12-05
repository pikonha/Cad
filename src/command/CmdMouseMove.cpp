#include "CmdMouseMove.h"
#include "MainCmd.h"
#include "LineModel.h"
#include "Line.h"

void CmdMouseMove(Data& d, MainScreen& s)
{
	MainCmd* cmd = Manager::getInstance()->getMainCmd();
	
	if (cmd->getDrawing()) {
		cmd->setP2(*s.getView()->getMousePos());

		LineModel* line = new LineModel(new Line(cmd->getItem()->getP1(), cmd->getItem()->getP2()));
		cmd->createAuxLine(line);

		s.getView()->draw(cmd->getAuxLine());
	}
}