#include "Manager.h"
#include "App.h"
#include "CmdNew.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdZoom.h"
#include "CmdLoad.h"
#include "CmdClear.h"
#include "CmdClose.h"
#include "CmdSetLine.h"
#include "CmdSetArch.h"
#include "CmdSetBezier.h"
#include "CmdMouseMove.h"
#include "CmdMouseClick.h"
#include "CmdMouseRelease.h"
#include "CmdSetStatusBar.h"
#include "CmdClearAllItems.h"
#include "CmdClearLastItem.h"


Manager* Manager::getInstance()
{
	if (!manager)
		manager = new Manager(App::getInstance());

	return manager;
}

void Manager::mousePressEvent()
{
	app->runCmd(new CmdMouseClick());
}

void Manager::mouseReleaseEvent()
{
	app->runCmd(new CmdMouseRelease());
}

void Manager::mouseMoveEvent()
{
	app->runCmd(new CmdMouseMove());

}

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

void Manager::clearLastItem()
{
	app->runCmd(new CmdClearLastItem());
}

void Manager::clearAllItems()
{
	app->runCmd(new CmdClearAllItems());
}

void Manager::setLine()
{
	app->runCmd(new CmdSetLine());
}

void Manager::setBezier()
{
	app->runCmd(new CmdSetBezier());
}

void Manager::setArch()
{
	app->runCmd(new CmdSetArch());
}
