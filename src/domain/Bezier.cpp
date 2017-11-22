#include "Bezier.h"
#include <QPainter>
#include <math.h>

void Bezier::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}

QPainterPath Bezier::getPath() const
{
	QPainterPath path(x);
	
	for (float t = 0; t <= 1; t += 0.0002) {
		QPoint b = pow((1 - t), 2) * x + (2 * (1 - t) * t * y) + pow(t, 2)* z;
		path.lineTo(b);
	}

	return path;
}

Bezier::Bezier(const QPoint& x, const QPoint& y, const QPoint& z, QGraphicsItem* parent) : QGraphicsItem(parent)
{
	this->x = x;
	this->y = z;
	this->z = y;
}

QRectF Bezier::boundingRect() const{
	/*return getPath().boundingRect();*/
	return QRectF(0, 0, 1920, 1080);
}

