#include "Item.h"

bool Item::operator==(Item * i)
{
   return (x == i->getP1()) && (y == i->getP2());
}
