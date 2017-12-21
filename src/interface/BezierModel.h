#pragma once
#ifndef INCLUDED_BEZIERMODEL_H
#define INCLUDED_BEZIERMODEL_H
#include "Model.h"

class BezierModel : public Model
{
   Bezier bz;
public:
	BezierModel(const Bezier& _bz, QGraphicsItem* parent = 0) : bz(_bz), Model(bz, parent) {}
	~BezierModel() {}
};

#endif