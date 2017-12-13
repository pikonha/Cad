#pragma once
#ifndef INCLUDED_BEZIERMODEL_H
#define INCLUDED_BEZIERMODEL_H
#include "Model.h"

class BezierModel : public Model
{
public:
	BezierModel() : Model() {}
	BezierModel(Item* i, QGraphicsItem* parent = 0) : Model(i, parent) {}
	~BezierModel() {}
};

#endif