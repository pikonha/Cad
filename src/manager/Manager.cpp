#include "Manager.h"
#include "../app/App.h"

void Manager::mousePressEvent()
{
	if (App::getInstance()->getCurrentItem() == nullptr)
		App::getInstance()->deleteCurrentItem();


}

void Manager::mouseReleaseEvent()
{

}

void Manager::mouseMoveEvent()
{

}

void Manager::newFile()
{

}

void Manager::openFile()
{

}

void Manager::clearFile()
{

}

void Manager::closeFile()
{

}

void Manager::line()
{

}

void Manager::bezier()
{

}

void Manager::arch()
{

}

void Manager::clearLastItem()
{

}

void Manager::drawAuxLine()
{
}
