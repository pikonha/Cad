#include "CmdMouseRelease.h"

void CmdMouseRelease::execute(Data& d, MainScreen& s)
{
	d.setAuxDraw(false);
	s.getView()->setMouseTracking(false);

	if (d.getForm() == LINE)
		d.pushItem();

	else if (d.getForm() == ARCH && d.getCurrentItem() && !d.getFirstClick()) {
		d.setDrawingArch(true);
		s.getView()->setMouseTracking(true);
	}
}