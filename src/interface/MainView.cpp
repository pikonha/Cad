#include "MainView.h"
#include "QWidget"
#include "MainScreen.h"
#include "Item.h"
#include "Line.h"
#include "Bezier.h"
#include "Arch.h"

#include "LineModel.h"
#include "BezierModel.h"
#include "ArchModel.h"
#include "../manager/Manager.h"

MainView::MainView(Manager* m)
{
	manager = m;

	setMinimumSize(1920, 1020);
	showMaximized();

	scene = new QGraphicsScene(this);
	setScene(scene);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void MainView::draw(Item* item)
{
	itemCast(item);
	scene->addItem(item);
	scene->update();\
}

QGraphicsItem* itemCast(Item* item)
{
	if (Line* l = dynamic_cast<Line*>(item))
		return new LineModel(l->getP1(), l->getP2());
}


void MainView::mousePressEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mousePressEvent();

	event->accept();
}

void MainView::mouseReleaseEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mouseReleaseEvent();

	event->accept();	
}

void MainView::mouseMoveEvent(QMouseEvent* event)
{
	mousePos = qpointToPoint(event->pos());
	manager->mouseMoveEvent();
	
	event->accept();
}

void MainView::wheelEvent(QWheelEvent* event)
{
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	
	manager->wheelEvent();

	event->accept();
}

Point* MainView::qpointToPoint(QPoint p)
{
	Point* a = new Point(p.x(), p.y());
	return a;
}














