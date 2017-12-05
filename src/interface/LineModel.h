#pragma once
#ifndef INCLUDED_LINEMODEL_H
#define INCLUDED_LINEMODEL_H
#include <QGraphicsItem>
#include "Model.h"

class LineModel : public QGraphicsItem, public Model
{
public:
	LineModel() {}
	LineModel(Item* i, QGraphicsItem* parent = 0) : QGraphicsItem(parent), Model(i) {}
	~LineModel() {}

protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();
};

#endif