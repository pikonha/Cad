#include "MainCmd.h"
#include "Data.h"

//void MainCmd::setMessageToScreen(Instruction in)
//{ 
//   screen.setStatusMessage(in);
//}

void MainCmd::setDrawing(bool drwOk)
{
   drawing = drwOk;
   data.getCurrentFile()->getView()->setMouseTracking(drwOk);
}

void MainCmd::setAuxDraw(bool status)
{
   auxDraw = status;
   data.getCurrentFile()->getView()->setMouseTracking(status);
}


