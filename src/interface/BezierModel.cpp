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
	QPainterPath path(*pointConversor(bezier->getPoints().front()));

	for (int i = 1; i < bezier->getPoints().size() ; i++) {

		path.lineTo(*pointConversor(bezier->getPoints().at(i)));
	}

	return path;
}

BezierModel::BezierModel(Bezier* b, QGraphicsItem* parent) : QGraphicsItem(parent)
{
	bezier = b;
}

QRectF BezierModel::boundingRect() const {
	return QRectF(0, 0, 1920, 1080);
}


QPoint* BezierModel::pointConversor(Point p)
{
	return new QPoint(p.getX(), p.getY());
}

