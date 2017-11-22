#pragma once
#ifndef INCLUDED_BEZIER_H
#define INCLUDED_BEZIER_H
#include <QGraphicsItem>


class Bezier : public QGraphicsItem
{
private:
	QPoint x;
	QPoint y;
	QPoint z;

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath() const;
public:
	Bezier() {}
	Bezier(const QPoint& x, const QPoint& y, const QPoint& z, QGraphicsItem* parent = 0);
};

#endif