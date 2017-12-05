#pragma once
#ifndef INCLUDED_ARCHMODEL_H
#define INCLUDED_ARCHMODEL_H
#include <QGraphicsItem>
#include "Model.h"

class ArchModel : public QGraphicsItem, public Model
{
public:
	ArchModel() {}
	ArchModel(Item* i, QGraphicsItem* parent = 0) : QGraphicsItem(parent), Model(i) {}
	~ArchModel() {}

protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();

	QPoint* pointConversor(Point p);
};

#endif