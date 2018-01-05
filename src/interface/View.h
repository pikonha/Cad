#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QGraphicsView>
#include "../data/Point.h"

class Geometry;
class Manager;

class View : public QGraphicsView
{
   QPainter* painter;
	Manager* manager;

   QGraphicsScene* scene;
public:
   ~View() {}
	View(Manager* m, /*double widht, double heigth,*/ QWidget* parent);	

   QGraphicsScene* getScene() const { return scene; }

   /////DRAW
   void draw(Geometry* geo);
   void drawAuxLine(Point p1,Point p2) const;

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

   void setShortcuts();
};

#endif