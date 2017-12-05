#include "Data.h"
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"


/////ITEMS

void Data::clearItens()
{
	for (int i = 0; i < itens.size(); i++)
		delete itens.at(i);

	itens.clear();
}



