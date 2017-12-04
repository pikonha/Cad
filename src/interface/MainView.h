#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H
#include <QtGui>
#include "Point.h"
#include <QGraphicsView>
#include "../manager/Manager.h"

class MainView : public QGraphicsView
{
	Q_OBJECT
private:
	QGraphicsScene* scene;
	Manager* manager;

	Point* mousePos;
public:
	MainView(Manager* m);
	~MainView() {}

	Point* getMousePos() { return mousePos; }

	QGraphicsScene* getScene() { return scene; }

	void draw(Item* item);	
	
	Point* qpointToPoint(QPoint p);

	QGraphicsItem* itemCast(Item* item);
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif