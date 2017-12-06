#include "CmdMouseMove.h"
#include "MainCmd.h"

void CmdMouseMove(Data& d, MainScreen& s)
{
	MainCmd* cmd = Manager::getInstance()->getMainCmd();
	
	if (cmd->getDrawing() || cmd->getAuxDraw())  {
		
		if(cmd->getForm() == LINE)
			cmd->setP2(*s.getView()->getMousePos());

		if (cmd->getForm() != LINE)
		{
			cmd->createAuxLine(cmd->getItem()->getP1(), cmd->getItem()->getP2());
			s.getView()->draw(cmd->getAuxLine());
		}

		
	}
}