#pragma once
#ifndef INCLUDED_AUXLINEMODEL_H 
#define INCLUDED_AUXLINEMODEL_H
#include "Model.h"
#include "Line.h"

class AuxLineModel : public Model
{
public:
	AuxLineModel(const Point& p, const Point& o, QGraphicsItem* parent = 0) : Model(new Line(p, o), parent) {}
	~AuxLineModel() {}
};

#endif