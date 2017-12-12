#include "Model.h"
#include <QPainter>

bool Model::operator==(Model* m)
{
	if (item->operator==(m->getItem()))
		return true;

	return false;
}

QRectF Model::boundingRect() const
{
	return QRectF(0, 0, 1920, 1080);
}

void Model::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}

QPoint* Model::pointConversor(Point* p)
{
	return new QPoint(p->getX(), p->getY());
}

QPainterPath Model::getPath()
{
	QPainterPath path(*pointConversor(item->getPoints().front()));

	for (int i = 1; i < item->getPoints().size(); i++)
		path.lineTo(*pointConversor(item->getPoints().at(i)));

	return path;
}