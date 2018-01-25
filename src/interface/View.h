#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QWidget>
#include "../data/Point.h"
#include <memory>

class Manager;
class Geometry;

#include <QPainter>

class View : public QWidget
{
   Q_OBJECT

	Manager* manager;
   QPainter painter;
   QPixmap map;

   int scale;

   void setShortcuts();
public:
   ~View() {}
	View(Manager* m, QWidget* parent = 0);	

   /////SCALE
   int getScale() const { return scale; }
   void setScale(const int s) { scale = s; }
  
   /////DRAW
   void clearView();

   /////CAST
   static Point qpointToPoint(QPoint p);
   static QPoint pointToQPoint(Point p1);

   /////SAVE
   std::string getSavePath();
   std::string getLoadPath();
   void saveFile();

   /////START CMD MAIN
   void startLineCommand() const;
   void startBezierCommand() const;
   void startArchCommand() const;

   void clearAllItems();
   void clearLastItem();

   void addPath(Geometry* geo);
   QPainterPath getPath(Geometry* geo) const;

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
   
   void dragMoveEvent(QDragMoveEvent* event) override;

   void paintEvent(QPaintEvent* event) override;
};

#endif