#include "Data.h"
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"

Data::Data()
{
	currentForm = LINE;
	auxDraw = drawingArch = false;
	firstClick = true;
	currentItem = new Line();
}

Data::~Data()
{
	delete currentItem;
	delete auxLine;
}

/////FORM
Form Data::getForm()
{
	switch (currentForm)
	{
	case LINE: return LINE;
	case BEZIER: return BEZIER;
	case ARCH: return ARCH;
	}
}

/////ITEMS
void Data::clearItens()
{
	itens.clear();
}

void Data::deleteCurrentItem() {
	if (currentItem)
		delete currentItem;
}

void Data::pushItem()
{
	itens.push_back(currentItem);
	currentItem = nullptr;
}

void Data::setAuxLine()
{
	auxLine = new Line(x, y);
}


/////DRAW
void Data::setNextDraw()
{
	deleteCurrentItem();

	if ( currentForm == LINE)
		currentItem = new Line(x, y);

	else if (currentForm == BEZIER)
		currentItem = new Bezier(x, y, z);

	else if (currentForm == ARCH)
		currentItem = new Arch(x, y, z);

	pushItem();
	drawingArch = false;
}

void Data::setCurrentItemNoParameters()
{
	if (currentForm == LINE)
		currentItem = new Line();

	if (currentForm == BEZIER)
		currentItem = new Bezier();

	if (currentForm == ARCH)
		currentItem = new Arch();
}