#pragma once
#ifndef INCLUDED_ARCHMODEL_H
#define INCLUDED_ARCHMODEL_H
#include "Model.h"

class ArchModel :public Model
{
   Arch a;
public:
   ArchModel(const Arch& _a,QGraphicsItem* parent = 0) : a(_a), Model(a,parent) {}
	~ArchModel() {}
};

#endif