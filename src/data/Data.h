#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <deque>
#include "FormType.h"
#include "Geometry.h"

class Item;

class Data
{
private:
	FormType currentForm;

	std::deque<Geometry*> allGeos;
public:
	~Data() { clearGeometries(); }
	Data() { currentForm= LINE; }

	/////FORM
	FormType getForm() { return currentForm; }
	void setForm(const FormType fType) { currentForm = fType; }

	/////ITENS	
	void addGeometry(Geometry* geo) { allGeos.push_back(geo); }
	void clearGeometries();

	std::deque<Geometry*>& getGeometries() { return allGeos; }

	Geometry* getLastGeometry() { return allGeos.back(); }

};

#endif