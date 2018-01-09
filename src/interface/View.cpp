#include <QtGui>
#include "View.h"
#include "../data/Geometry.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

View::View(Manager* m, /*double widht, double heigth,*/ QWidget* parent) : QWidget(parent)
{
   setAutoFillBackground(true);
   setBackgroundRole(QPalette::Base);   

   manager= m;

   image = new QImage(QApplication::desktop()->size(),QImage::Format_ARGB32_Premultiplied);
   painter = new QPainter(image);

	//setMinimumSize(widht, heigth);
   setMinimumSize(1920,1080);

   setShortcuts();
}

////////////////////////////////////////////////////////////////////////////////

void View::draw(Geometry* geo)
{
   std::vector<Point> points = geo->getPoints();

   for (int i= 1; i < points.size(); i++)
   {
      int j = i - 1;
      painter->drawLine(points[i].x,points[i].y,points[j].x,points[j].y);
   }

   update();
}

void View::drawAuxLine(Point p1, Point p2) const
{   
   painter->drawLine(p1.x,p1.y,p2.x,p2.y);
}

void View::eraseGeo(Geometry* geo)
{
   painter->setPen(Qt::white);
   draw(geo);
   painter->setPen(Qt::black);
}

////////////////////////////////////////////////////////////////////////////////

void View::mousePressEvent(QMouseEvent* event)
{
	manager->mousePressEvent(qpointToPoint(event->pos()));

	event->accept();
}

void View::mouseReleaseEvent(QMouseEvent* event)
{
	manager->mouseReleaseEvent(qpointToPoint(event->pos()));

	event->accept();	
}

void View::mouseMoveEvent(QMouseEvent* event)
{
	manager->mouseMoveEvent(qpointToPoint(event->pos()));
	
	event->accept();
}

void View::wheelEvent(QWheelEvent* event)
{
	//setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	
	manager->wheelEvent();

	event->accept();
}

void View::paintEvent(QPaintEvent* event)
{
   QPainter p(this);
   p.drawImage(0,0,*image);
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
