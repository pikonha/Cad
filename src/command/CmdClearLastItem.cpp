#include "CmdClearLastItem.h"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
	d.deleteLastItem();
	s.getView()->eraseLastItem();
}