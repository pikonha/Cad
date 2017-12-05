#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"

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

void MainCmdArch::draw()
{
	ArchModel* a = new ArchModel(arch);
	view->getScene()->addItem(a);
}
