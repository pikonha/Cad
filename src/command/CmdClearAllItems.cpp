#include "CmdClearAllItems.h"
#include "Item.h"

void CmdClearAllItems::execute(Data& d, MainScreen& s)
{

	for (int i = 0; i < d.getItens().size(); i++)
		delete d.getItens().at(i);

	d.getItens().clear();
	s.getView()->getScene()->clear();
}