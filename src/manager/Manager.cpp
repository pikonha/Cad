#include "Cmd.h"
#include "CmdNew.h"
#include "Manager.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClose.h"
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

/////CMD
void Manager::startLineCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdLine(screen);
   cmdmain->execute(data,screen);
}

void Manager::startBezierCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdBezier(screen);
   cmdmain->execute(data,screen);
}

void Manager::startArchCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdArch(screen);
   cmdmain->execute(data,screen);
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
   cmdmain->mousePressEvent(screen.getView()->getMousePos());
}

void Manager::mouseReleaseEvent()
{
   cmdmain->mouseReleaseEvent(screen.getView()->getMousePos(), data);

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
   cmdmain->mouseMoveEvent(screen.getView()->getMousePos());
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
   runCmd(new CmdSave());
}

void Manager::openFile()
{

}


void Manager::closeFile()
{
   runCmd(new CmdClose());
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

