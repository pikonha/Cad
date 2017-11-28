#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H
#include <QtGui>
#include <QGraphicsView>
#include "Manager.h"

class MainView : public QGraphicsView
{
	Q_OBJECT
private:
	QGraphicsScene* scene;
	Manager* manager;

	QPoint mousePos;
public:
	MainView(Manager* m);
	~MainView() {}

	QPoint getMousePos() { return mousePos; }

	QGraphicsScene* getScene() { return scene; }

	void draw(QGraphicsItem* item);	
	
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif