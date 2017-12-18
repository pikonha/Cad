#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"
#include "AuxLineModel.h"

void MainCmdArch::execute(Data& d, MainScreen& s)
{
	d.setForm(ARCH);
	arch = new Arch();
}

void MainCmdArch::setP1(Point* p)
{
	arch->setX(p);
	arch->setCenter(p);
}

void MainCmdArch::setP2(Point* p)
{
	arch->setY(p);
	arch->setRaio();	
}

void MainCmdArch::setP3(Point* p)
{
	arch->setZ(p);
	arch->setControl(p);
	draw();
}

QGraphicsItem* MainCmdArch::getModel()
{
	return new ArchModel(arch);
}

void MainCmdArch::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      setP1(&p);
      setAuxDraw(true,screen.getView());
   }
   else
   {
      setDrawing(false,screen.getView());
      secondClick = true;
   }
}

void MainCmdArch::mouseReleaseEvent(Point& p,Data& d)
{
   if (!secondClick)
   {
      setAuxDraw(false,screen.getView());
      setDrawing(true,screen.getView());
   }
   else {
      d.addItem(getItem());
      screen.getView()->save(getModel());
   }
}

void MainCmdArch::mouseMoveEvent(Point& p)
{
   if ( auxDraw )
   {
      setP2(&p);
      createAuxLine(arch->getP1(),arch->getP2());

      screen.getView()->draw(getAuxLine());
   }
   else if( drawing )
   {
      if (auxLine) {
         delete auxLine;
         auxLine = nullptr;
      }

      setP3(&p);
   }
}

