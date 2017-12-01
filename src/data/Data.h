#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H
#include <vector>
#include "Point.h"

class Item;

enum Form { LINE, BEZIER, ARCH };

class Data
{
private:
	Form currentForm;

	Point x;
	Point y;
	Point z;

	Item* currentItem;
	Item* auxLine;

	bool auxDraw;
	bool drawingArch;
	bool firstClick;

	std::vector<Item*> itens;

public:
	Data();
	~Data();

	/////FORM
	Form getForm();
	void setForm(Form shape) { currentForm = shape; }

	/////ITENS
	void addItem(Item* item) { itens.push_back(item); }
	void clearItens();
	void pushItem();

	Item* getCurrentItem() { return currentItem; }
	void setCurrentItem(Item* item)  { currentItem = item; }
	void deleteCurrentItem();
	void setCurrentItemNoParameters();

	Item* getAuxLine() { return auxLine; }
	void setAuxLine();

	std::vector<Item*> getItens() { return itens; }
	int getItensSize() { return itens.size(); }

	Item* getLastItem() { return itens.back(); }
	void deleteLastItem() { itens.pop_back(); }	

	/////POINTS
	Point getX() { return x; }
	Point getY() { return y; }
	Point getZ() { return z; }
	
	void setX(Point p) { x = p; }
	void setY(Point p) { y = p; }
	void setZ(Point p) { z = p; }

	void clearPoints() { x = y = z = Point(0, 0); }

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