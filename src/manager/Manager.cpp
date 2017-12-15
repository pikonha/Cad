#include "Cmd.h"
#include "CmdNew.h"
#include "Manager.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClear.h"
#include "CmdClose.h"
#include "MainCmdLine.h"
#include "MainCmdArch.h"
#include "CmdMouseMove.h"
#include "CmdWheelEvent.h"
#include "CmdMouseClick.h"
#include "MainCmdBezier.h"
#include "CmdMouseRelease.h"
#include "CmdSetStatusBar.h"
#include "CmdClearAllItems.h"
#include "CmdClearLastItem.h"

Manager::Manager(Data* d) : cmdmain(nullptr)
{
	data = d;
	cmd = new CmdIdle();
}

/////CMD
void Manager::setLine()
{
	if (cmdmain)
		delete cmdmain;

	cmdmain = new MainCmdLine(screen);
	cmdmain->execute(*data, *screen);
}

void Manager::setBezier()
{
	if (cmdmain)
		delete cmdmain;

	cmdmain = new MainCmdBezier(screen);
	cmdmain->execute(*data, *screen);
}

void Manager::setArch()
{
	if (cmdmain)
		delete cmdmain;

	cmdmain = new MainCmdArch(screen);
	cmdmain->execute(*data, *screen);
}

void Manager::runCmd(Cmd* command)
{
	cmd = command;
	cmd->execute(*data, *screen);
	delete cmd;
	cmd = new CmdIdle();
}

/////MOUSE
void Manager::mousePressEvent()
{
	runCmd(new CmdMouseClick());
}

void Manager::mouseReleaseEvent()
{
	runCmd(new CmdMouseRelease());

	if (cmdmain->getForm() == LINE)
		setLine();

	else
	{
		if (cmdmain->getSecondClick())
		{
			if (cmdmain->getForm() == BEZIER)
				setBezier();

			else if (cmdmain->getForm() == ARCH)
				setArch();
		}
	}
}

void Manager::mouseMoveEvent()
{
	runCmd(new CmdMouseMove());
}

void Manager::wheelEvent()
{
	runCmd(new CmdWheelEvent());
}

/////FILE
void Manager::newFile()
{

}

void Manager::saveFile()
{

}

void Manager::openFile()
{

}

void Manager::clearFile()
{

}

void Manager::closeFile()
{

}

/////ITEMS
void Manager::clearLastItem()
{
	runCmd(new CmdClearLastItem());
}

void Manager::clearAllItems()
{
	runCmd(new CmdClearAllItems());
}

