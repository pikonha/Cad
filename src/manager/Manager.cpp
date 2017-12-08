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

Manager::Manager(Data* d, MainScreen* s)
{
	data = d;
	screen = s;
	setLine();
	cmd = new CmdIdle();
}

/////CMD
void Manager::setLine()
{
	cmdmain = new MainCmdLine(data, screen->getView(), LINE);
}

void Manager::setBezier()
{
	cmdmain = new MainCmdBezier(data, screen->getView(), BEZIER);
}

void Manager::setArch()
{
	cmdmain = new MainCmdArch(data, screen->getView(), ARCH);
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

