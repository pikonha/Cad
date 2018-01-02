#include "MainCmd.h"

//void MainCmd::setMessageToScreen(Instruction in)
//{ 
//   screen.setStatusMessage(in);
//}

void MainCmd::setDrawing(bool drwOk)
{
   drawing = drwOk;
   view.setMouseTracking(drwOk);
}

void MainCmd::setAuxDraw(bool status)
{
   auxDraw = status;
   view.setMouseTracking(status);
}

void MainCmd::save(Geometry* geo)
{
   file.addGeo(geo);
}

void MainCmd::draw(Geometry* geo)
{
   view.draw(geo);
}

