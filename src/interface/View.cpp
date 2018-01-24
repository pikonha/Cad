#include <QtGui>
#include "View.h"
#include "../data/Geometry.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

View::View(Manager* m, QWidget* parent) : QWidget(parent)
{
   setAutoFillBackground(true);
   setBackgroundRole(QPalette::Base);   

   manager= m;
   scale = 100;

   setMaximumSize(QApplication::desktop()->size());

   setShortcuts();
   startLineCommand();

   setCursor(QCursor(Qt::CrossCursor));
}

////////////////////////////////////////////////////////////////////////////////

void View::clearView()
{
  
}

void View::addPath(Geometry* geo)
{
   std::vector<Point> points = geo->getPoints();
   
   QPainterPath path;

   path.moveTo(points[0].x,points[0].y);

   for (int i= 1; i < points.size(); i++)
   {
      path.lineTo(points[i].x,points[i].y);
   }

   geoPaths.push_back(GeoPath(geo,path));

   update();
}

void View::removePath(Geometry* geo) 
{
   for (int i= 0; i < geoPaths.size(); i++)
   {
      if (geoPaths[i].geo == geo)
         geoPaths.erase(geoPaths.begin() + i);
   }
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
}

void View::paintEvent(QPaintEvent* event)
{
   clearView();

   QPainter p;
   p.begin(this);
  
   for (GeoPath geo : geoPaths)
      p.drawPath(geo.path);

   p.end();
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
