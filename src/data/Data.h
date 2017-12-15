#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <deque>
#include "Point.h"
#include "FormType.h"

class Item;

class Data
{
private:
	FormType currentForm;

	std::deque<Item*> itens;
public:
	~Data() { clearItens(); }
	Data() { currentForm= LINE; }

	/////FORM
	FormType getForm() { return currentForm; }
	void setForm(const FormType fType) { currentForm = fType; }

	/////ITENS	
	void addItem(Item* item) { itens.push_back(item); }
	void clearItens();

	std::deque<Item*> getItens() { return itens; }

	Item* getLastItem() { return itens.back(); }
	void deleteLastItem() { itens.pop_back(); }

};

#endif