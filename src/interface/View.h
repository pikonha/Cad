#pragma once
#ifndef INCLUDED_VIEW_H
#define INCLUDED_VIEW_H

#include <QGraphicsView>
#include "Point.h"
#include "File.h"

class Manager;

class View : public QGraphicsView
{
	Point mousePos;

   QPainter& painter;

	Manager* manager;
   File* file;
public:
   ~View() { delete file; }
	View(QPainter& painter, QWidget* parent);	

	void setManager(Manager& m) { manager = &m; }

	Point getMousePos() const { return mousePos; }

   void reprint();
	void draw(Geometry* geo);
   void drawAuxLine(Point p1,Point p2);

   static Point qpointToPoint(QPoint p);
   static QPoint pointToQPoint(Point p1);

   File& getFile() const { return *file; }

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif