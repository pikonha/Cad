#include "App.h"
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

Manager* Manager::manager = nullptr;
Manager* Manager::getInstance()
{
	if (!manager)
		manager = new Manager(App::getInstance());

	return manager;
}

/////DOMAIN
void Manager::setLine()
{
	app->setCmdMain(new MainCmdLine(app->getData(), app->getView(), LINE));
}

void Manager::setBezier()
{
	app->setCmdMain(new MainCmdBezier(app->getData(), app->getView(), BEZIER));
}

void Manager::setArch()
{
	app->setCmdMain(new MainCmdArch(app->getData(), app->getView(), ARCH));
}

/////MOUSE
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

void Manager::wheelEvent()
{
	app->runCmd(new CmdWheelEvent());
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
	app->runCmd(new CmdClearLastItem());
}

void Manager::clearAllItems()
{
	app->runCmd(new CmdClearAllItems());
}

/////APP
MainCmd* Manager::getMainCmd()
{
	return app->getCmdMain();
}