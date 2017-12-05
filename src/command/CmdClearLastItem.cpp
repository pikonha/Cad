#include "CmdClearLastItem.h"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
	s.getView()->eraseLastItem();
}