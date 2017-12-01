#include "ArchModel.h"
#include <QPainter>
#include "Point.h"
#include "Arch.h"

ArchModel::ArchModel(QPoint a, QPoint b, QPoint c)
{
	Point x(a.x(), a.y());
	Point y(b.x(), b.y());
	Point z(c.x(), c.y());

	arch = new Arch(x, y, z);
}


QPainterPath ArchModel::getPath()
{
	QPainterPath path(*pointConversor(arch->getPoints().front()));

	for (int i = 1; i < arch->getPoints().size(); i++) {
		path.lineTo(*pointConversor(arch->getPoints().at(i)));
	}

	return path;
}


void ArchModel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(getPath());
}


QPoint* ArchModel::pointConversor(Point p)
{
	return new QPoint(p.getX(), p.getY());
}
