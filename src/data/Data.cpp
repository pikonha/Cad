#include "Data.h"
#include "Item.h"

/////ITEMS

void Data::clearItens()
{
	for (int i = 0; i < itens.size(); i++)
		delete itens[i];

	itens.clear();
}



