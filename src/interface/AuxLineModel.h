#pragma once
#ifndef INCLUDED_AUXLINEMODEL_H 
#define INCLUDED_AUXLINEMODEL_H
#include "Model.h"
#include "Line.h"

class AuxLineModel : public Model
{
   Line tmpLine;
public:
   ~AuxLineModel() {}
   AuxLineModel(const Point& p, const Point& o, QGraphicsItem* parent = 0) : tmpLine(p,o),Model(tmpLine, parent) {}
};

#endif