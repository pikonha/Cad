#include "Manager.h"
#include "App.h"

#include "MainCmdLine.h"


#include "CmdNew.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClear.h"
#include "CmdClose.h"
#include "CmdMouseMove.h"
#include "CmdWheelEvent.h"
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

/////LINE
void Manager::setLine()
{
	app->setCmdMain(new MainCmdLine());
}

void Manager::setP1Line(Point p)
{
	app->getCmd()->setP1(app->getData, p);
}

void Manager::setP2Line(Point p)
{
	app->getCmd()->setP2(app->getData, p);
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
