#include "CmdMouseMove.h"
#include "MainCmd.h"
#include "..//app/App.h"

void CmdMouseMove::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = App::getInstance()->getManager()->getCmdMain();
	
	if (cmd->getAuxDraw())
	{
		cmd->createAuxLine(cmd->getItem()->getP1(), cmd->getItem()->getP2());
		s.getView()->draw(cmd->getAuxLine());
	}


	if (cmd->getDrawing() )  {
		
		if (cmd->getForm() == LINE)
			cmd->setP2(s.getView()->getMousePos());

		else
			cmd->setP3(s.getView()->getMousePos());
		
	}
}