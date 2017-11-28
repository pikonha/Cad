#include "CmdMouseMove.h"

void CmdMouseMove(Data& d, MainScreen& s)
{
	if (!d.getCurrentItem())
		return;

	if (!d.getDrawingArch())
		d.setY(s.getView()->getMousePos());

	if (d.getForm() == LINE)
	{
		d.setNextDraw();
		s.getView()->draw(d.getCurrentItem());
	}

	if (!d.getDrawingArch())
	{
		if (d.getAuxDraw())
			s.getView()->getScene()->removeItem(d.getAuxLine());

		d.setAuxLine();
		s.getView()->getScene()->addItem(d.getAuxLine());
		s.getView()->getScene()->update();

		d.setAuxDraw(true);
	}
	else
	{
		d.setZ(s.getView()->getMousePos());
		s.getView()->getScene()->removeItem(d.getAuxLine());
		d.setNextDraw();
		s.getView()->draw(d.getCurrentItem());
	}

}