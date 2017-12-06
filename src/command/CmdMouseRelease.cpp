#include "CmdMouseRelease.h"
#include "MainCmd.h"

void CmdMouseRelease::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = Manager::getInstance()->getMainCmd();

	if (cmd->getForm() == LINE)
		s.getView()->save(cmd->getModel());
}