#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"
#include "AuxLineModel.h"

void MainCmdArch::execute()
{
	data->setForm(ARCH);
	arch = new Arch();
}

void MainCmdArch::setP1(Point p)
{
	arch->setX(p);
}

void MainCmdArch::setP2(Point p)
{
	arch->setY(p);
}

void MainCmdArch::setP3(Point p)
{
	arch->setZ(p);
	draw();
}

QGraphicsItem* MainCmdArch::getModel()
{
	return new ArchModel(arch);
}

