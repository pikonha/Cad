#include <QtGui>
#include "Point.h"
#include "View.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>

View::View(Manager* m, /*double widht, double heigth,*/ QWidget* parent) : QGraphicsView(parent), painter(QPainter(this))
{
   manager= m;
	//setMinimumSize(widht, heigth);
   setMinimumSize(1920,1080);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   setShortcuts();
}

////////////////////////////////////////////////////////////////////////////////

void View::drawAuxLine(Point p1, Point p2)
{
   painter.drawLine(pointToQPoint(p1),pointToQPoint(p2));
}

////////////////////////////////////////////////////////////////////////////////

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

void View::setShortcuts()
{
   QShortcut* undone = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z),this);
   connect(undone,&QShortcut::activated,this,&View::clearLastItem);

   QShortcut* saveSc = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this);
   connect(saveSc,&QShortcut::activated,this,&View::saveFile);
}

////////////////////////////////////////////////////////////////////////////////

Point View::qpointToPoint(QPoint p)
{
	return Point(p.x(), p.y());
}

QPoint View::pointToQPoint(Point p1)
{   
   return QPoint(p1.x,p1.y);
}

////////////////////////////////////////////////////////////////////////////////

std::string View::getSavePath()
{
   return QFileDialog::getSaveFileName(this,QString("Save File"),"",QString("Dat files (*.dat)")).toStdString();
}

std::string View::getLoadPath()
{
   return QFileDialog::getOpenFileName(this,QString("Open file"),"",QString("Dat files (*.dat)")).toStdString();
}

void View::saveFile()
{
   manager->saveFile();
}

////////////////////////////////////////////////////////////////////////////////

void View::clearAllItems()
{
   manager->clearAllItems();
}

void View::clearLastItem()
{
   manager->clearLastItem();
}

////////////////////////////////////////////////////////////////////////////////

void View::startLineCommand() const
{
   manager->startArchCommand();
}

void View::startBezierCommand() const
{
   manager->startBezierCommand();
}

void View::startArchCommand() const
{
   manager->startArchCommand();
}
