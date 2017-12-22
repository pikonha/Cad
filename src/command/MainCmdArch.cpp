#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"
#include "AuxLineModel.h"

void MainCmdArch::execute(Data& d, MainScreen& s)
{
	d.setForm(ARCH);
   setMessageToScreen(MOUSECLICK);
}

void MainCmdArch::setP1(const Point& p)
{
   p1= p;
   setMessageToScreen(MOUSEMOVE);
}

void MainCmdArch::setP2(const Point& p)
{
   p2= p;
}

void MainCmdArch::setP3(const Point& p)
{
   p3 = p;
	draw();
}

QGraphicsItem* MainCmdArch::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;

   geoModel = new ArchModel(Arch(p1,p2,p3));

   return geoModel;
}

void MainCmdArch::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      setP1(p);
      setAuxDraw(true);
   }
   else
   {
      setDrawing(false);
      secondClick = true;
   }
}

void MainCmdArch::mouseReleaseEvent(Point& p,Data& d)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);
      setMessageToScreen(SECONDCLICK);
   }
   else {
      d.addGeometry(getNewGeometry());
      screen.getView()->save(geoModel);
   }
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if ( auxDraw )
   {
      setP2(p);
      createAuxLine(p1,p2);

      screen.getView()->draw(getAuxLine());
   }
   else if( drawing )
   {
      if (auxLine) {
         delete auxLine;
         auxLine = nullptr;
      }

      setP3(p);
   }
}

