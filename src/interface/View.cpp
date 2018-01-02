#include <QtGui>
#include "Point.h"
#include "File.h"
#include "View.h"
#include "../manager/Manager.h"

View::View(QPainter& paint, QWidget* parent) : painter(paint), QGraphicsView(parent), file(new File("NewFile"))
{
	setMinimumSize(1920, 880);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::reprint()
{
   std::vector<Geometry*> geos = file->getGeos();

   for (int i= 0; i < geos.size(); i++)
      draw(geos[i]);
}

void View::draw(Geometry* geo)
{
   std::vector<Point> points = geo->getPoints();

   for (int i= 0; i < points.size(); i++)
      painter.drawPoint(points.at(i).x, points.at(i).y);      
}

void View::drawAuxLine(Point p1, Point p2)
{
   painter.drawLine(pointToQPoint(p1),pointToQPoint(p2));
}

void View::mousePressEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mousePressEvent();

	event->accept();
}

void View::mouseReleaseEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mouseReleaseEvent();

	event->accept();	
}

void View::mouseMoveEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mouseMoveEvent();
	
	event->accept();
}

void View::wheelEvent(QWheelEvent* event)
{
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	
	manager->wheelEvent();

	event->accept();
}

Point View::qpointToPoint(QPoint p)
{
	return Point(p.x(), p.y());
}

QPoint View::pointToQPoint(Point p1)
{
   return QPoint(p1.x,p1.y);
}
