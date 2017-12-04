#include "LineModel.h"
#include <QPainter>
#include "Point.h"
#include "Line.h"

LineModel::~LineModel()
{
	delete line;
}

LineModel::LineModel(Line* l, QGraphicsItem* parent) : QGraphicsItem(parent)
{
	line = l;
}


void LineModel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}


QPainterPath LineModel::getPath()
{
	QPoint* a = new QPoint(line->getP1().getX(), line->getP1().getY());
	QPoint* b = new QPoint(line->getP2().getX(), line->getP2().getY());

	QPainterPath path(*a);
	path.lineTo(*b);
	return path;
}

QRectF LineModel::boundingRect() const
{
	return QRectF(0, 0, 1920, 1080);
}



