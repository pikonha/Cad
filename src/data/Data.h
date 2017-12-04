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

	Item* auxLine;

	bool auxDraw;
	bool firstClick;

	std::vector<Item*> itens;

public:
	Data();
	~Data();

	//LINE
	void prepareLine();

	/////FORM
	Form getForm();
	void setForm(Form shape) { currentForm = shape; }

	/////ITENS	
	void addItem(Item* item) { itens.push_back(item); }
	void clearItens();

	Item* getAuxLine() { return auxLine; }
	void setAuxLine();

	std::vector<Item*> getItens() { return itens; }
	int getItensSize() { return itens.size(); }

	Item* getLastItem() { return itens.back(); }
	void deleteLastItem() { itens.pop_back(); }	

	

	/////DRAW
	bool getAuxDraw() { return auxDraw; }
	
	bool getFirstClick() { return firstClick; }

	void setAuxDraw(bool status) { auxDraw = status; }
	
	void setFirstClick(bool status) { firstClick = status; }

	void setNextDraw();
};

#endif