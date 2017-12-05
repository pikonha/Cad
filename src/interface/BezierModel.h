#pragma once
#ifndef INCLUDED_BEZIERMODEL_H
#define INCLUDED_BEZIERMODEL_H
#include <QGraphicsItem>
#include "Model.h"

class BezierModel : public QGraphicsItem, public Model
{
public:
	BezierModel() {}
	BezierModel(Item* i, QGraphicsItem* parent = 0) : QGraphicsItem(parent), Model(i) {}
	~BezierModel() {}

protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();

	QPoint* pointConversor(Point p);
};

#endif