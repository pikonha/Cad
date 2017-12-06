#pragma once
#ifndef INCLUDED_ARCHMODEL_H
#define INCLUDED_ARCHMODEL_H
#include "Model.h"

class ArchModel :public Model
{
public:
	ArchModel() {}
	ArchModel(Item* i, QGraphicsItem* parent = 0) : Model(i, parent) {}
	~ArchModel() {}
};

#endif