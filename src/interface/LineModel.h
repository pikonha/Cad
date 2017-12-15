#pragma once
#ifndef INCLUDED_LINEMODEL_H
#define INCLUDED_LINEMODEL_H
#include "Model.h"

class LineModel : public Model
{
public:
	LineModel() : Model() {}
	LineModel(Item* i, QGraphicsItem* parent = 0) : Model(i, parent) {}
	~LineModel() {}
};

#endif