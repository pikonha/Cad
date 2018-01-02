#include "Cmd.h"
#include "CmdNewFile.h"
#include "Manager.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClose.h"
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

/////CMD
void Manager::startLineCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdLine(View(screen.getPainter(),&screen), File("NewFile"));
}

void Manager::startBezierCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdBezier(View(screen.getPainter(),&screen),File("NewFile"));
}

void Manager::startArchCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdArch(View(screen.getPainter(),&screen),File("NewFile"));
}

void Manager::runCmd(Cmd* command)
{
   cmd= command;
   cmd->execute(data,screen);
   delete cmd;
   cmd= new CmdIdle();
}

/////MOUSE
void Manager::mousePressEvent()
{
   cmdmain->mousePressEvent(screen.getCurrentView().getMousePos());
}

void Manager::mouseReleaseEvent()
{
   cmdmain->mouseReleaseEvent(screen.getCurrentView().getMousePos(), data);

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
   cmdmain->mouseMoveEvent(screen.getCurrentView().getMousePos());
}

void Manager::wheelEvent()
{
   runCmd(new CmdWheelEvent());
}

/////FILE
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

/////ITEMS
void Manager::clearLastItem()
{
   runCmd(new CmdClearLastItem());
}

void Manager::clearAllItems()
{
   runCmd(new CmdClearAllItems());
}

