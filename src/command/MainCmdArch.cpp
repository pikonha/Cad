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

