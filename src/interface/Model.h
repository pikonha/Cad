#pragma once
#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H
#include "Geometry.h"
#include <QGraphicsItem>

class Model : public QGraphicsItem
{
public:
   virtual ~Model() {}

	Model(Geometry* ig, QGraphicsItem* parent = 0) : QGraphicsItem(parent), geo(ig) {}

   Geometry& getGeo() const { return *geo; }

	bool operator==(Model* m);
	
protected:
   Geometry* geo;

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();

	QPoint pointConversor(const Point& p);
};

#endif
