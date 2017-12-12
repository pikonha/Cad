#include "Item.h"

bool Item::operator==(Item * i)
{
	if (x->operator==(i->getP1()) && y->operator==(i->getP2()))
		return true;

	return false;
}
