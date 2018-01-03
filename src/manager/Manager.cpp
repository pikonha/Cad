#include "Cmd.h"
#include "Manager.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClose.h"
#include "CmdNewFile.h"
#include "CmdDiscard.h"
#include "MainCmdLine.h"
#include "MainCmdArch.h"
#include "CmdWheelEvent.h"
#include "MainCmdBezier.h"
#include "CmdClearAllItems.h"
#include "CmdClearLastItem.h"

Manager::Manager(Data& d,MainScreen& s) : data(d),screen(s),cmdmain(nullptr)
{
   cmd= new CmdIdle();
   startLineCommand();
}

Manager::~Manager()
{
   delete cmd; 
   delete cmdmain;
}

////////////////////////////////////////////////////////////////////////////////

void Manager::startLineCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdLine(data);
}

void Manager::startBezierCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdBezier(data);
}

void Manager::startArchCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdArch(data);
}

void Manager::runCmd(Cmd* command)
{
   cmd= command;
   cmd->execute(data,screen);
   delete cmd;
   cmd= new CmdIdle();
}

////////////////////////////////////////////////////////////////////////////////

void Manager::mousePressEvent()
{
   cmdmain->mousePressEvent(data.getCurrentFile()->getView()->getMousePos());
}

void Manager::mouseReleaseEvent()
{
   cmdmain->mouseReleaseEvent(data.getCurrentFile()->getView()->getMousePos());

   if (cmdmain->getForm() == LINE)
      startLineCommand();
  
   else if (cmdmain->getSecondClick()) 
   {
      if (cmdmain->getForm() == BEZIER)
         startBezierCommand();

      else if (cmdmain->getForm() == ARCH)
         startArchCommand();
   }
}

void Manager::mouseMoveEvent()
{
   cmdmain->mouseMoveEvent(data.getCurrentFile()->getView()->getMousePos());
}

void Manager::wheelEvent()
{
   runCmd(new CmdWheelEvent());
}

////////////////////////////////////////////////////////////////////////////////

void Manager::newFile()
{
   runCmd(new CmdNewFile());
}

void Manager::saveFile()
{
   runCmd(new CmdSave());
}

void Manager::openFile()
{
   runCmd(new CmdLoad());
}

void Manager::closeFile()
{
   runCmd(new CmdClose());
}

void Manager::discardFile(int tab)
{
   runCmd(new CmdDiscard(tab));
}

////////////////////////////////////////////////////////////////////////////////

void Manager::clearLastItem()
{
   runCmd(new CmdClearLastItem());
}

void Manager::clearAllItems()
{
   runCmd(new CmdClearAllItems());
}

