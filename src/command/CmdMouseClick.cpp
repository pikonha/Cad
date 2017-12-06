#include "CmdMouseClick.h"
#include "Item.h"
#include "MainCmd.h"

void CmdMouseClick::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = Manager::getInstance()->getMainCmd();

	if (!cmd->getDrawing()) {
		cmd->setP1(*s.getView()->getMousePos());

		if (cmd->getForm() == LINE)
			cmd->setDrawing(true);

		else
			cmd->setAuxDraw(true);
	}
}