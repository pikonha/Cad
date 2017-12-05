#pragma once
#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H
#include "Item.h"

class Model 
{
protected:
	Item* item;
public:
	Model() {}
	Model(Item* i) { item = i; }
	virtual ~Model() {}

	Item* getItem() { return item; }

	bool operator==(Model* m);
};

#endif
