#include "MainView.h"
#include "QWidget"
#include "MainScreen.h"
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


void MainView::draw(QGraphicsItem* item)
{
	scene->addItem(item);
	scene->update();
}


void MainView::mousePressEvent(QMouseEvent* event)
{
	mousePos = event->pos();
	manager->mousePressEvent();

	event->accept();
}

void MainView::mouseReleaseEvent(QMouseEvent* event)
{
	mousePos = event->pos();
	manager->mouseReleaseEvent();

	event->accept();	
}

void MainView::mouseMoveEvent(QMouseEvent* event)
{
	mousePos = event->pos();
	manager->mouseMoveEvent();
	
	event->accept();
}

void MainView::wheelEvent(QWheelEvent* event)
{
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	double scaleF = 1.15;

	if (event->delta() > 0)
		scale(scaleF, scaleF);
	else
		scale(1 / scaleF, 1 / scaleF);

	event->accept();
}














