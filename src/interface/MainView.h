#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H
#include <QGraphicsView>
#include "../manager/Manager.h"

class Point;
class Model;

class MainView : public QGraphicsView
{
private:
	QGraphicsScene* scene;

	Point* mousePos;

	std::vector<QGraphicsItem*> items;

	Manager* manager;
public:
	MainView();
	~MainView() {}

	void setManager(Manager& m) { manager = &m; }

	Point* getMousePos() { return mousePos; }

	QGraphicsScene* getScene() { return scene; }

	void draw(QGraphicsItem* model);	

	void save(QGraphicsItem* model);
	void erase(Model* model);
	void eraseLastItem();
	
	Point* qpointToPoint(QPoint p);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif