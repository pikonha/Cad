#pragma once
#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H
#include <QGraphicsView>
#include <vector>
#include <QGraphicsItem>

class Line;

enum Form
{
	LINE, BEZIER, ARCH
};

class MainView : public QGraphicsView
{
private:
	QPixmap map;
	QGraphicsScene* scene;
	Form shape;
	QGraphicsItem* currentItem;

	QPoint x;
	QPoint y;
	QPoint z;

	bool firstClick;
	bool auxDraw;
	bool drawingArch;
	QGraphicsItem* auxLine;

	std::vector<QGraphicsItem*> itens;
public:
	MainView();
	~MainView() {}

	QGraphicsScene* getScene() { return scene; }

	void draw();	
	void drawAuxiliarLine();

	void setLine() { shape = LINE; }
	void setBezier() { shape = BEZIER; }
	void setArch() { shape = ARCH; }

	std::string getCurrentShape();

	void saveFile();
	void openFile();

	void clearItens();
	void clearLastItem();
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
};

#endif