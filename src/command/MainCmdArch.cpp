#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"
#include "AuxLineModel.h"

void MainCmdArch::execute(Data& d, MainScreen& s)
{
	d.setForm(ARCH);
	arch = new Arch();
}

void MainCmdArch::setP1(const Point& p)
{
	arch->setP1(p);
	arch->setCenter(p);
}

void MainCmdArch::setP2(const Point& p)
{
	arch->setP2(p);
	arch->setRaio();	
}

void MainCmdArch::setP3(const Point& p)
{
	arch->setP3(p);
	arch->setControl(p);
	draw();
}

QGraphicsItem* MainCmdArch::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;

   geoModel = new ArchModel(arch);

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
   }
   else {
      d.addGeometry(&getGeometry());
      screen.getView()->save(getQtGraphicGeo());
   }
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if ( auxDraw )
   {
      setP2(p);
      createAuxLine(arch->getP1(),arch->getP2());

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

