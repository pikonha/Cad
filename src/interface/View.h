#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QWidget>
#include "../data/Point.h"

class Geometry;
class Manager;

class View : public QWidget
{
   QPainter* painter;
	Manager* manager;
   QImage* image;

   int scale;

   void setShortcuts();
public:
   ~View() {}
	View(Manager* m, int w, int h, QWidget* parent = 0);	

   /////SCALE
   int getScale() const { return scale; }
   void setScale(int s) { scale = s; }

   /////DRAW
   void draw(Geometry* geo);
   //void reprint();
   void eraseGeo(Geometry* geo);

   /////CAST
   static Point qpointToPoint(QPoint p);
   static QPoint pointToQPoint(Point p1);

   /////SAVE
   std::string getSavePath();
   std::string getLoadPath();
   void saveFile();

   /////DELETE GEOS
   void clearAllItems();
   void clearLastItem();

   /////START CMD MAIN
   void startLineCommand() const;
   void startBezierCommand() const;
   void startArchCommand() const;

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;

   void paintEvent(QPaintEvent* event) override;

   void resizeEvent(QResizeEvent* event) override;
};

#endif