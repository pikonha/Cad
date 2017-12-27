#include <QtGui>
#include "Point.h"
#include "Model.h"
#include "File.h"
#include "View.h"
#include "../manager/Manager.h"


View::~View()
{
   deleteAllItems();
   delete scene;
}

View::View(QWidget* parent) : QGraphicsView(parent), file(new File("NewFile"))
{
	setMinimumSize(1920, 880);

	scene = new QGraphicsScene(this);
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::save(QGraphicsItem* model) 
{
	items.push_back(model);
}

void View::erase(Model* model) 
{
	for (int i = 0; i < items.size(); i++) {
		Model* m = dynamic_cast<Model*>(items.at(i));
		
		if ( m == model )
			items.erase(items.begin() + i);
	}
}

void View::deleteAllItems()
{
   for (int i= 0; i < items.size(); i++)
      delete items[i];

   items.clear();
}

void View::reprint()
{
   scene->clear();

   for (int i= 0; i < items.size(); i++)
      draw(items.at(i));
}

void View::draw(QGraphicsItem* model)
{
	scene->addItem(model);
	scene->update();
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
