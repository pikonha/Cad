#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H
#include <vector>
#include "Point.h"
#include "Form.h"

class Item;

class Data
{
private:
	Form currentForm;

	std::vector<Item*> itens;

public:
	Data() { currentForm = LINE;  }
	~Data() { clearItens(); }

	/////FORM
	Form getForm() { return currentForm;  }
	void setForm(Form shape) { currentForm = shape; }

	/////ITENS	
	void addItem(Item* item) { itens.push_back(item); }
	void clearItens();

	std::vector<Item*> getItens() { return itens; }

	Item* getLastItem() { return itens.back(); }
	void deleteLastItem() { itens.pop_back(); }	

};

#endif