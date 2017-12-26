#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H

#include <deque>
#include <QGraphicsView>
#include "Point.h"
#include "File.h"

class Manager;
class Model;

class MainView : public QGraphicsView
{
	QGraphicsScene* scene;

	Point mousePos;

	std::deque<QGraphicsItem*> items;

	Manager* manager;
   File& file;
public:
   ~MainView(){}
	MainView();	

	void setManager(Manager& m) { manager = &m; }

	Point getMousePos() { return mousePos; }

	QGraphicsScene* getScene() { return scene; }

	void draw(QGraphicsItem* model);	

	void save(QGraphicsItem* model);
	void erase(Model* model);

   void reprint();
	
	Point qpointToPoint(QPoint p);

   std::deque<QGraphicsItem*>& getItems() { return items; }

   File getFile() { return file; }

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif