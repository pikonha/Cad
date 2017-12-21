#pragma once
#ifndef INCLUDED_LINEMODEL_H
#define INCLUDED_LINEMODEL_H
#include "Model.h"

class LineModel : public Model
{
   Line ln;
public:
   ~LineModel() {}
   LineModel(const Line& _ln, QGraphicsItem* parent = 0) : ln(_ln),Model(ln, parent) {}
};

#endif