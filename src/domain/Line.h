#pragma once
#ifndef INCLUDED_LINE_H
#define INCLUDED_LINE_H
#include <QGraphicsItem>

class Line : public QGraphicsItem
{
private:
	QPoint x;
	QPoint y;

	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	QPainterPath getPath();
public:
	Line() {}
	Line(const QPoint& x, const QPoint& y, QGraphicsItem* parent = 0);
	~Line() {}
};

#endif