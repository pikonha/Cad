#include "CmdMouseClick.h"
#include "Item.h"
#include "MainCmd.h"

void CmdMouseClick::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = Manager::getInstance()->getMainCmd();

	if (cmd->getDrawing())
		cmd->setDrawing(false);

	else {
		cmd->setP1(*s.getView()->getMousePos());
		cmd->setDrawing(true);
	}
}