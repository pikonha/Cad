#include <QtGui>
#include "View.h"
#include "../data/Geometry.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

View::View(Manager* m, int w, int h, QWidget* parent) : QWidget(parent)
{
   setAutoFillBackground(true);
   setBackgroundRole(QPalette::Base);   

   manager= m;
   scale = 100;

   image = new QImage(QApplication::desktop()->size(),QImage::Format_ARGB32_Premultiplied);
   painter = new QPainter(image);
   
   setFixedSize(w,h);
   setMinimumSize(w, h);
   setMaximumSize(1920,1080);

   setShortcuts();
   startLineCommand();
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

void View::eraseGeo(Geometry* geo)
{
   if (geo) {
      painter->setPen(Qt::white);
      draw(geo);
      painter->setPen(Qt::black);
   }
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

void View::resizeEvent(QResizeEvent* event)
{
  
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
   manager->startLineCommand();
}

void View::startBezierCommand() const
{
   manager->startBezierCommand();
}

void View::startArchCommand() const
{
   manager->startArchCommand();
}
