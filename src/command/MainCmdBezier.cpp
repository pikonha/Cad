#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute(Data& d, MainScreen& s)
{
	d.setForm(BEZIER);
	bezier = new Bezier();
}

void MainCmdBezier::setP1(const Point& p)
{
	bezier->setP1(p);
}

void MainCmdBezier::setP2(const Point& p)
{
	bezier->setP2(p);
}

void MainCmdBezier::setP3(const Point& p)
{
	bezier->setZ(p);
	draw();
}

QGraphicsItem* MainCmdBezier::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;

   geoModel = new BezierModel(bezier);

   return geoModel;
}

void MainCmdBezier::mousePressEvent(Point& p)
{
   if (!drawing)
   {
      setP1(p);
      setAuxDraw(true);
   }
   else
   {
      setDrawing(false);
      secondClick = true;
   }
}

void MainCmdBezier::mouseReleaseEvent(Point& p,Data& d)
{
   if (!secondClick)
   {
      setAuxDraw(false);
      setDrawing(true);
   }
   else
   {
      d.addGeometry(&getGeometry());
      screen.getView()->save(geoModel);
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      setP2(p);
      createAuxLine(bezier->getP1(),bezier->getP2());

      screen.getView()->draw(getAuxLine());
   }
   else if (drawing)
   {
      if (auxLine) {
         delete auxLine;
         auxLine = nullptr;
      }

      setP3(p);
   }
}