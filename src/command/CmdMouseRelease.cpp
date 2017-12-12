#include "CmdMouseRelease.h"
#include "MainCmd.h"
#include "..//app/App.h"

void CmdMouseRelease::execute(Data& d, MainScreen& s)
{
	MainCmd* cmd = App::getInstance()->getManager()->getCmdMain();

	if (cmd->getForm() == LINE) 
	{
		s.getView()->save(cmd->getModel());
		d.addItem(cmd->getItem());
		cmd->setDrawing(false, s.getView());
	}
	else
	{
		cmd->setDrawing(true, s.getView());
		cmd->setAuxDraw(false, s.getView());
	}

}