#include "CmdMouseClick.h"
#include "MainCmd.h"
#include "../app/App.h"

void CmdMouseClick::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = App::getInstance()->getManager()->getCmdMain();

	if (!cmd->getDrawing())
	{
		cmd->setP1(s.getView()->getMousePos());

		if (cmd->getForm() == LINE)
			cmd->setDrawing(true, s.getView());

		else
			cmd->setAuxDraw(true, s.getView());
	}
	else {
		if (cmd->getForm() != LINE)
		{
			s.getView()->save(cmd->getModel());
			d.addItem(cmd->getItem());
		}
	}
}