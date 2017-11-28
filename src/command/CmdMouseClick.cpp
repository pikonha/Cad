#include "CmdMouseClick.h"

void CmdMouseClick::execute(Data& d, MainScreen& s)
{
	d.deleteCurrentItem();
	d.setCurrentItemNoParameters();

	if (d.getFirstClick())
	{
		d.setX(s.getView()->getMousePos());

		if (d.getForm() != LINE)
			d.setFirstClick(false);
	}
	else
	{
		if (d.getForm() == BEZIER)
		{
			d.setZ(s.getView()->getMousePos());

			d.setAuxDraw(false);

			s.getView()->getScene()->removeItem(d.getAuxLine());
		}

		d.setNextDraw();
		s.getView()->draw(d.getCurrentItem());
		d.setFirstClick(true);
	}

	if (d.getCurrentItem())
		s.getView()->setMouseTracking(true);
	else
		s.getView()->setMouseTracking(false);
}