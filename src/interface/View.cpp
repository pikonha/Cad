#include <QtGui>
#include "View.h"
#include "../data/Geometry.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>
#include <QApplication>
#include <QDebug>


View::View(Manager* m, QWidget* parent) : QWidget(parent), map(parentWidget()->size())
{
   setAutoFillBackground(true);
   setBackgroundRole(QPalette::Base);   

   manager= m;
   scale = 100;
   draw = false;

   painter.begin(&map);
   painter.setTransform(transform);

   x = painter.viewport().x();
   y = painter.viewport().y();

   clearMap();

   setShortcuts();
   startLineCommand();

   setCursor(QCursor(Qt::CrossCursor));
}

////////////////////////////////////////////////////////////////////////////////

void View::clearMap()
{
   map.fill();
}

void View::drawInScreen( Geometry& geo)
{ 
   drawMap(geo);
   update();
}

void View::drawMap(Geometry& geo)
{
   painter.drawPath(getPath(geo));
}

QPainterPath View::getPath( Geometry& geo) const
{
   std::vector<Point> points = geo.getPoints();

   QPainterPath auxPath;

   auxPath.moveTo(points[0].x,points[0].y);

   for (const auto p : points)
      auxPath.lineTo(p.x,p.y);

   return auxPath;
}

////////////////////////////////////////////////////////////////////////////////

void View::mousePressEvent(QMouseEvent* event)
{
   const auto point = getWorldPos(event->pos());

   if (event->button() == Qt::LeftButton) {     
      manager->mousePressEvent(point);
      setDraw(true);
   }

   else {
      manager->dragInitEvent(point);
      setMouseTracking(true);
   }

   event->accept();
}

void View::mouseReleaseEvent(QMouseEvent* event)
{
   const auto point = getWorldPos(event->pos());

   if (event->button() == Qt::LeftButton) 
      manager->mouseReleaseEvent(point);
   
   else {
      setCursor(QCursor(Qt::CrossCursor));
      setMouseTracking(false);
   }

   event->accept();
}

void View::mouseMoveEvent(QMouseEvent* event)
{
   const auto point = getWorldPos(event->pos());
   if (draw) 
      manager->mouseMoveEvent(point);
   
   else
      manager->dragMoveEvent(point);

   event->accept(); 
}

void View::paintEvent(QPaintEvent* event)
{
   QPainter painterScreen(this); 

   painterScreen.drawPixmap(painter.viewport(),map);    

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

void View::setScale(const int s)
{
   scale = s;
}

void View::changeViewPort(const Point point)
{
   transform.translate(point.x,point.y);
   painter.setTransform(transform);
}

void View::changeScale(double percent)
{
   transform.scale(percent,percent);
   painter.setTransform(transform);
}

Point View::getWorldPos(QPoint pos)
{
   const auto invTransform = painter.transform().inverted();
   auto worldPos = invTransform * pos;
   return qpointToPoint(worldPos);
}

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
