#include "MainCmdBezier.h"
#include "Bezier.h"
#include "BezierModel.h"

void MainCmdBezier::execute(Data& d, MainScreen& s)
{
	d.setForm(BEZIER);
   setMessageToScreen(MOUSECLICK);
}

void MainCmdBezier::setP1(const Point& p)
{
   p1= p;
   setMessageToScreen(MOUSEMOVE);
}

void MainCmdBezier::setP2(const Point& p)
{
   p2= p;
}

void MainCmdBezier::setP3(const Point& p)
{
   p3= p;
	draw();
}

QGraphicsItem* MainCmdBezier::getQtGraphicGeo()
{
   if (geoModel)
      delete geoModel;

   geoModel = new BezierModel(Bezier(p1,p2,p3));

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
      setMessageToScreen(SECONDCLICK);
   }
   else
   {
      d.addGeometry(getNewGeometry());
      screen.getView()->save(geoModel);
   }
}

void MainCmdBezier::mouseMoveEvent(Point& p)
{  
   if (auxDraw)
   {
      setP2(p);
      createAuxLine(p1,p2);

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