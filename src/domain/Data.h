#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H
#include <vector>
#include <qwidget.h>
#include <qgraphicsitem.h>

enum Form { LINE, BEZIER, ARCH };

class Data
{
private:
	Form currentForm;

	QPoint x;
	QPoint y;
	QPoint z;

	QGraphicsItem* currentItem;
	QGraphicsItem* auxLine;

	bool auxDraw;
	bool drawingArch;
	bool firstClick;

	std::vector<QGraphicsItem*> itens;

public:
	Data();
	~Data();

	/////FORM
	Form getForm();
	void setForm(Form shape) { currentForm = shape; }

	/////ITENS
	void addItem(QGraphicsItem* item) { itens.push_back(item); }
	void clearItens();
	void pushItem();

	QGraphicsItem* getCurrentItem() { return currentItem; }
	void setCurrentItem(QGraphicsItem* item) { currentItem = item; }
	void deleteCurrentItem();
	void setCurrentItemNoParameters();

	QGraphicsItem* getAuxLine() { return auxLine; }
	void setAuxLine();

	int getItensSize() { return itens.size(); }
	QGraphicsItem* getLastItem() { return itens.back(); }
	void deleteLastItem() { itens.pop_back(); }
	std::vector<QGraphicsItem*> getItens() { return itens; }

	/////POINTS
	QPoint getX() { return x; }
	QPoint getY() { return y; }
	QPoint getZ() { return z; }
	
	void setX(QPoint p) { x = p; }
	void setY(QPoint p) { y = p; }
	void setZ(QPoint p) { z = p; }

	void clearPoints() { x = y = z = QPoint(0, 0); }

	/////DRAW
	bool getAuxDraw() { return auxDraw; }
	bool getDrawingArch() { return drawingArch; }
	bool getFirstClick() { return firstClick; }

	void setAuxDraw(bool status) { auxDraw = status; }
	void setDrawingArch(bool status) { drawingArch = status; }
	void setFirstClick(bool status) { firstClick = status; }

	void setNextDraw();
};

#endif