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
   setMaximumSize(1910,1070);

   setShortcuts();
   startLineCommand();

   setCursor(QCursor(Qt::CrossCursor));
}

////////////////////////////////////////////////////////////////////////////////

void View::draw(Geometry& geo)
{
   std::vector<Point> points = geo.getPoints();

   for (int i= 1; i < points.size(); i++)
   {
      int j = i - 1;
      painter->drawLine(points[i].x,points[i].y,points[j].x,points[j].y);
   }

   update();
}

void View::eraseGeo(Geometry& geo)
{
   painter->setPen(Qt::white);
   
   std::vector<Point> points = geo.getPoints();

   for (int i= 1; i < points.size(); i++)
   {
      int j = i - 1;

      QPoint p1(points[i].x,points[i].y);
      QPoint p2(points[j].x,points[j].y);

      if ( image->pixelColor(p1).value() <= 0 || image->pixelColor(p2).value() <= 0)
         painter->drawLine(p1,p2);
   }

   update();

  /* draw(geo);*/

   painter->setPen(Qt::black);
}

////////////////////////////////////////////////////////////////////////////////

void View::mousePressEvent(QMouseEvent* event)
{
   if (event->button() == Qt::LeftButton) 
      manager->mousePressEvent(qpointToPoint(event->pos()));

   else
      setCursor(QCursor(Qt::ClosedHandCursor));

   event->accept();
}

void View::mouseReleaseEvent(QMouseEvent* event)
{
   if (event->button() == Qt::LeftButton)
      manager->mouseReleaseEvent(qpointToPoint(event->pos()));      
  
   else
      setCursor(QCursor(Qt::CrossCursor));

   event->accept();
}

void View::mouseMoveEvent(QMouseEvent* event)
{
   manager->mouseMoveEvent(qpointToPoint(event->pos()));

   event->accept(); 
}

void View::dragMoveEvent(QDragMoveEvent* event)
{
   //double i = Point::distance(qpointToPoint(event->pos()),qpointToPoint(event->oldPos()));
}


void View::paintEvent(QPaintEvent* event)
{
   QPainter p(this);
   p.drawImage(0,0,*image);
   event->accept();
}

void View::setShortcuts()
{
   QShortcut* undo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z),this);
   connect(undo,&QShortcut::activated,this,&View::clearLastItem);

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
