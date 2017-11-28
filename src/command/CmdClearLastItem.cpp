#include "CmdClearLastItem.h"


void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
	if (d.getItensSize() == 0)
		return;

	s.getView()->getScene()->removeItem(d.getLastItem());
	d.deleteLastItem();
	s.getView()->getScene()->update();
}