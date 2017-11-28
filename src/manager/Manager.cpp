#include "Manager.h"
#include "../app/App.h"
#include "../domain/Line.h"
#include "../command/CmdNew.h"
#include "../command/CmdIdle.h"
#include "../command/CmdSave.h"
#include "../command/CmdZoom.h"
#include "../command/CmdLoad.h"
#include "../command/CmdClear.h"
#include "../command/CmdClose.h"
#include "../command/CmdSetLine.h"
#include "../command/CmdSetArch.h"
#include "../command/CmdSetBezier.h"
#include "../command/CmdMouseMove.h"
#include "../command/CmdMouseClick.h"
#include "../command/CmdMouseRelease.h"
#include "../command/CmdSetStatusBar.h"
#include "../command/CmdClearAllItems.h"
#include "../command/CmdClearLastItem.h"

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
