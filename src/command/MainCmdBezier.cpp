#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute(Data& d, MainScreen& s)
{
	d.setForm(BEZIER);
	bezier = new Bezier();
}

void MainCmdBezier::setP1(Point* p)
{
	bezier->setX(p);
}

void MainCmdBezier::setP2(Point* p)
{
	bezier->setY(p);
}

void MainCmdBezier::setP3(Point* p)
{
	bezier->setZ(p);
	draw();
}

QGraphicsItem* MainCmdBezier::getModel()
{
	return new BezierModel(bezier);
}

void MainCmdBezier::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      setP1(&p);
      setAuxDraw(true,screen.getView());
   }
   else
   {
      setDrawing(false,screen.getView());
      secondClick = true;
   }
}

void MainCmdBezier::mouseReleaseEvent(Point& p,Data& d)
{
   if (!secondClick)
   {
      setAuxDraw(false,screen.getView());
      setDrawing(true,screen.getView());
   }
   else
   {
      d.addItem(getItem());
      screen.getView()->save(getModel());
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      setP2(&p);
      createAuxLine(bezier->getP1(),bezier->getP2());

      screen.getView()->draw(getAuxLine());
      return;
   }
   else if (drawing)
   {
      if (auxLine) {
         delete auxLine;
         auxLine = nullptr;
      }

      setP3(&p);
   }
}