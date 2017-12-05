#include "BezierModel.h"
#include <QPainter>
#include <math.h>
#include "Bezier.h"


void BezierModel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}

QPainterPath BezierModel::getPath()
{
	QPainterPath path(*pointConversor(item->getPoints().front()));

	for (int i = 1; i < item->getPoints().size() ; i++) 
		path.lineTo(*pointConversor(item->getPoints().at(i)));

	return path;
}


QRectF BezierModel::boundingRect() const
{
	return QRect(0, 0, 1920, 1080); 
}


QPoint* BezierModel::pointConversor(Point p)
{
	return new QPoint(p.getX(), p.getY());
}

