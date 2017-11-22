#include "Line.h"
#include <QPainter>
#include <QPoint>


Line::Line(const QPoint& x, const QPoint& y, QGraphicsItem* parent) : QGraphicsItem(parent)
{
	this->x = x;
	this->y = y;
}


void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}


QPainterPath Line::getPath()
{
	QPainterPath path(x);
	path.lineTo(y);
	return path;
}

QRectF Line::boundingRect() const
{
	return QRectF(0, 0, 1920, 1080);
}



