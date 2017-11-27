#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H
#include <QGraphicsView>

class MainView : public QGraphicsView
{
private:
	QGraphicsScene* scene;
public:
	MainView();
	~MainView() {}

	QGraphicsScene* getScene() { return scene; }

	void draw();	
	void drawAuxiliarLine();
	
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif