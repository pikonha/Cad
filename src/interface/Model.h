#pragma once
#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H
#include "Item.h"
#include <QGraphicsItem>

class Model : public QGraphicsItem
{
public:
	Model() {}
	Model(Item* i, QGraphicsItem* parent = 0) : QGraphicsItem(parent) { item = i; }
	virtual ~Model() {}

	Item* getItem() { return item; }

	bool operator==(Model* m);
	
protected:
	Item* item;

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();

	QPoint* pointConversor(Point* p);
};

#endif
