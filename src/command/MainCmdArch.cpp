#include "MainCmdArch.h"
#include "ArchModel.h"
#include "Arch.h"

void MainCmdArch::execute()
{
	data->setForm(ARCH);
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
	screen->getView()->getScene()->addItem(a);
}

void MainCmdArch::pressMouse()
{
	if (!drawingArch)
		setP1(*screen->getView()->getMousePos());
}

void MainCmdArch::moveMouse()
{
	setP2(*screen->getView()->getMousePos());
}

void MainCmdArch::releaseMouse()
{
	drawingArch = true;
}