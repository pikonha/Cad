#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QWidget>
#include "../data/Point.h"

class Manager;
class Geometry;

#include <QPainter>

class View : public QWidget
{
   Q_OBJECT

	Manager* manager;
   QPainter painter;

   QPixmap mapWorld;

   int scale;

   void setShortcuts();
public:
   ~View() {}
	View(Manager* m, QWidget* parent = 0);	

   /////SCALE
   int getScale() const { return scale; }
   void setScale(const int s);
   QPixmap mapTransform();

   /////SAVE
   std::string getSavePath();
   std::string getLoadPath();
   void saveFile(); 

   /////DRAW
   void clearScreen();
   void clearPixmap();

   void clearAllItems();
   void clearLastItem();

   void drawInScreen( Geometry& geo);
   void drawInPixmap( Geometry& geo);
   QPainterPath getPath( Geometry& geo) const;

   /////CAST
   static Point qpointToPoint(QPoint p);
   static QPoint pointToQPoint(Point p1);

   /////START CMD MAIN
   void startLineCommand() const;
   void startBezierCommand() const;
   void startArchCommand() const;
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
   
   void dragMoveEvent(QDragMoveEvent* event) override;

   void paintEvent(QPaintEvent* event) override;
};

#endif