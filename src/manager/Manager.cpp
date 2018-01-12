#include "Cmd.h"
#include "Manager.h"
#include "CmdIdle.h"
#include "CmdSave.h"
#include "CmdLoad.h"
#include "CmdClose.h"
#include "CmdNewFile.h"
#include "CmdDiscard.h"
#include "CmdCloseTab.h"
#include "MainCmdLine.h"
#include "MainCmdArch.h"
#include "MainCmdBezier.h"
#include "CmdClearAllItems.h"
#include "CmdClearLastItem.h"
#include "CmdSetCurrentFile.h"
#include "CmdSetZoom.h"

Manager::Manager(Data& d,MainScreen& s) : data(d),screen(s),cmdmain(nullptr)
{
   cmd= new CmdIdle();
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

   screen.setStatusMessage(Instruction::MOUSECLICK);
}

void Manager::startBezierCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdBezier(data);

   screen.setStatusMessage(Instruction::MOUSECLICK);
}

void Manager::startArchCommand()
{
   if (cmdmain)
      delete cmdmain;

   cmdmain= new MainCmdArch(data);

   screen.setStatusMessage(Instruction::MOUSECLICK);
}

void Manager::runCmd(Cmd* command)
{
   cmd= command;
   cmd->execute(data,screen);
   delete cmd;
   cmd= new CmdIdle();
}

void Manager::closeTab(QWidget* widget)
{
   runCmd(new CmdCloseTab(widget));
}

////////////////////////////////////////////////////////////////////////////////

void Manager::mousePressEvent(Point mousePosition)
{
   data.getCurrentFile()->setSaved(false);
   cmdmain->mousePressEvent(mousePosition);
}

void Manager::mouseReleaseEvent(Point mousePosition)
{
   cmdmain->mouseReleaseEvent(mousePosition);

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

void Manager::mouseMoveEvent(Point mousePosition)
{
   cmdmain->mouseMoveEvent(mousePosition);
}

void Manager::wheelEvent()
{
   
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

void Manager::setCurrentFileByTab(View* v)
{   
   runCmd(new CmdSetCurrentFile(data.getFileByView(v)));
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

void Manager::setZoom(int scale)
{
   runCmd(new CmdSetZoom(scale));
}

