#include <QtGui>
#include "View.h"
#include "../data/Geometry.h"
#include <QShortcut>
#include "../manager/Manager.h"
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

View::View(Manager* m, QWidget* parent) : QWidget(parent), map(QApplication::desktop()->size())
{
   setAutoFillBackground(true);
   setBackgroundRole(QPalette::Base);   

   manager= m;
   scale = 100;
   map.fill(Qt::transparent);

   painter.begin(&map);

   setMaximumSize(QApplication::desktop()->size());

   setShortcuts();
   startLineCommand();

   setCursor(QCursor(Qt::CrossCursor));
}

////////////////////////////////////////////////////////////////////////////////

void View::clearScreen()
{
   QPainter p(this);
   p.fillRect(p.window(),Qt::white);
}

void View::clearPixmap()
{   
   painter.fillRect(painter.window(),Qt::white);
}

void View::drawInScreen( Geometry& geo)
{ 
   clearScreen();
   drawInPixmap(geo);
   update();
}

void View::drawInPixmap( Geometry& geo)
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
   QPainter p(this);
   p.drawPixmap(painter.window(),map);
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
