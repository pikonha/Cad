#include "LineModel.h"
#include <QPainter>
#include "Point.h"
#include "Line.h"


void LineModel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}


QPainterPath LineModel::getPath()
{
	QPoint* a = new QPoint(item->getP1().getX(), item->getP1().getY());
	QPoint* b = new QPoint(item->getP2().getX(), item->getP2().getY());

	QPainterPath path(*a);
	path.lineTo(*b);
	return path;
}

QRectF LineModel::boundingRect() const
{
	return QRectF(0, 0, 1920, 1080);
}



