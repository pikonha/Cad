#include "QWidget"
#include "Model.h"
#include "MainView.h"
#include "LineModel.h"
#include "ArchModel.h"
#include "MainScreen.h"
#include "BezierModel.h"
#include "../manager/Manager.h"

MainView::MainView(Manager* m)
{
	manager = m;

	setMinimumSize(1920, 1080);
	showMaximized();

	scene = new QGraphicsScene(this);
	setScene(scene);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainView::save(QGraphicsItem* model) 
{
	items.push_back(model);
}

void MainView::erase(Model* model) 
{
	for (int i = 0; i < items.size(); i++) {
		Model* m = dynamic_cast<Model*>(items.at(i));
		
		if ( m->operator==(model) )
			items.erase(items.begin() + i);
	}
}

void MainView::eraseLastItem()
{
	items.erase(items.end());
}

void MainView::draw(QGraphicsItem* model)
{
	scene->addItem(model);
	scene->update();
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
	return new Point(p.x(), p.y());
}














