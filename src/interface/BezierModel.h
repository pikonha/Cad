#pragma once
#ifndef INCLUDED_BEZIERMODEL_H
#define INCLUDED_BEZIERMODEL_H
#include <QGraphicsItem>
#include "Point.h"

class Bezier;

class BezierModel : public QGraphicsItem
{
private:
	Bezier* bezier;

protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();
public:
	BezierModel() {}
	BezierModel(Bezier* b, QGraphicsItem* parent = 0);

	QPoint* pointConversor(Point p);
};

#endif